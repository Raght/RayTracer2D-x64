#include "Line.h"


Segment::Segment()
{
	p1 = olc::vf2d(0, 0);
	p2 = olc::vf2d(1, 0);
}

Segment::Segment(olc::vf2d point1, olc::vf2d point2)
{
	p1 = point1;
	p2 = point2;
}

olc::vf2d Segment::Normal(const olc::vf2d& lightRayDirection) const
{
	olc::vf2d line_vector = p1 - p2;

	olc::vf2d normal = { line_vector.y, -line_vector.x };

	if (normal.dot(lightRayDirection) > 0)
	{
		normal = { -line_vector.y, line_vector.x };
	}

	normal = normal.norm();

	return normal;
}

bool Segment::operator == (const Segment& other)
{
	return (p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1);
}

bool Segment::operator != (const Segment& other)
{
	Segment& line = *this;
	return !(line == other);
}