#pragma once
class IPhone
{
	// 속성
private:
	int volume;

	// 기능
public:
	IPhone();
	~IPhone() = default;
	
	// SETTER
	void SetVolume(const int& volume);
	// GETTER
	int GetVolume() const;
};

