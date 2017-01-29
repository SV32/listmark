#include <list>

int main()
{
	std::list<std::list<int>> ll;

	for (int i = 0; i < 1024; i++) {
		std::list<int> l;
		for (int j = 0; j < 1024; j++) {
			l.push_back(j);
		}
		ll.push_back(l);
	}

	for (auto&& l : ll) {
		for (auto&& i : l) {
			i ^= 128;
		}
	}
}
