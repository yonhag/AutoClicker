enum class Button { Left, Right };

struct Settings
{
	Settings(const Button button, const unsigned int cps) : _button(button), _cps(cps) {}

	Button _button;
	unsigned int _cps; // Clicks Per Second
};