void placement(double const u, int interval[], const int N) {
	for (int i = 0; i < N; ++i) {
		if (((double)i / 10 <= u) && (u <  ((double)(i + 1) / 10))) interval[i] += 1;
	}

}

void histogram_out(int interval[], const int N, const int n) {
	for (int i = 0; i < N; ++i) {
		std::cout << "[" << (double)i / 10 << ";" << (double)(i + 1) / 10 << "):    " << (double)interval[i] / n << std::endl;
	}
}