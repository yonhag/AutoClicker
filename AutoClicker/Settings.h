enum class MouseButton { Left, Right };

struct Settings
{
	Settings(const MouseButton button, const unsigned int cps) : _button(button), _cps(cps) {}

	MouseButton _button;
	unsigned int _cps; // Clicks Per Second
};