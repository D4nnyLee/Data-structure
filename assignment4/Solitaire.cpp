#include <iostream>

using namespace std;

class LinkList {
	private:
		struct node {
			int value;
			node *next;
			node (): value(0), next(NULL) {}
			node (int v): value(v), next(NULL) {}
		};
		node *header;
		node *tail;

	public:
		LinkList (): header(new node()), tail(header) {}

		void push_back(int n) {
			tail->next = new node(n);
			tail = tail->next;
		}

		void pop_front() {
			if (!header->next)
				return;
			node *tmp = header;
			header = header->next;
			delete tmp;
		}

		int front() {
			return header->next->value;
		}

		void display_all() {
			node *tmp = header;
			do {
				tmp = tmp->next;
				switch (tmp->value) {
					case 0:
						cout << "A ";
						break;
					case 10:
						cout << "J ";
						break;
					case 11:
						cout << "Q ";
						break;
					case 12:
						cout << "K ";
						break;
					default:
						cout << tmp->value + 1 << ' ';
				}
			}
			while (tmp != tail);
			cout << '\n';
		}
};
int main(int argc, char const *argv[]) {
	srand(time(NULL));
	LinkList list;
	bool *filled = new bool[13]();
	for (int cnt = 0; cnt < 13;) {
		int n = rand()%13;
		if (!filled[n]) {
			list.push_back(n);
			++cnt;
			filled[n] = true;
		}
	}
	delete [] filled;
	for (int discard = 12; discard >= 0;) {
		list.display_all();
		if (list.front() != discard)
			list.push_back(list.front());
		else
			--discard;
		list.pop_front();
	}
	return 0;
}
