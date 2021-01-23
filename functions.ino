int buttonClickHandler(const int *buttonPin, int *buttonState, int *previousButtonState, int holdDownAvailable) {
	*buttonState = digitalRead(*buttonPin);

	if (*buttonState == HIGH && *previousButtonState == LOW)
	{
		if (holdDownAvailable == 0)
			*previousButtonState = *buttonState;
		delay(500);
		return 1;
	}

	*previousButtonState = *buttonState;
	return 0;
}