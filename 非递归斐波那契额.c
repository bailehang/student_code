double fbla(double n) {
	double f = 0, g = 1;
	while (0<n--) {
		g = g + f;
		f = g - f;
	}
	return g;
}
