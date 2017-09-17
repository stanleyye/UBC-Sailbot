#include "StandardCalc.h"

StandardCalc::StandardCalc()
{
}


StandardCalc::~StandardCalc()
{
}

float StandardCalc::BoundTo180(float angle)
{
	if (angle >= -180.0f && angle < 180.0f) {
		return angle;
	} 

	// normalizes the angle between 0 and 360
	angle = fmod(angle, 360.0f);

	if (angle >= 180.0f) {
		angle -= 360.0f;
	}
	return angle;
}

bool StandardCalc::IsAngleBetween(float first_angle, float middle_angle, float second_angle)
{
	first_angle -= middle_angle;
	second_angle -= middle_angle;

	// normalize the angles
	normalize(first_angle);
	normalize(second_angle);

	if (first_angle * second_angle >= 0.0f) {
		return false;
	} else {
		return fabs(first_angle - second_angle) < 180.0f;
	}
}

void StandardCalc::normalize(float & angle)
{
	while (angle < -180.0f) {
		angle += 360.0f;
	}

	while (angle > 180.0f) {
		angle -= 360.0f;
	}
}

int main()
{

}
