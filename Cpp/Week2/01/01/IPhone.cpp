#include "IPhone.h"

IPhone::IPhone() : volume(0) {}

void IPhone::SetVolume(const int& volume)
{
	int temp = volume;
	if (volume > 100 || volume < 0)
	{
		if (volume > 100)
		{
			temp = 100;
		}
		else
		{
			temp = 0;
		}
	}
	this->volume = temp;
}

int IPhone::GetVolume() const
{
	return volume;
}
