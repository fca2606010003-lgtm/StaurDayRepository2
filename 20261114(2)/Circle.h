#pragma once
class Circle
{
	
private:
	float x;
	float y;

public:
	void Init();

	void Updata(float deltaTime);

	void Draw() const;

	void Reset();
};

