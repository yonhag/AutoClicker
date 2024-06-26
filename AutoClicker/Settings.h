struct Settings
{
	Settings(bool button, unsigned int cps) : _button(button), _cps(cps) {}

	bool _button; // Left - true, Right - False
	unsigned int _cps; // Clicks Per Second
};