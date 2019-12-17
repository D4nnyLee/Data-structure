#include <iostream>
#include <map>

using namespace std;

template <class ElementType>
class LinkList {
	private:
		struct node {
			ElementType element;
			node *next;
			node (): element(ElementType()), next(NULL) {}
			node (ElementType e, node *n): element(e), next(n) {}
		};
		node *header;
        map<ElementType, int> group;
	public:
		LinkList (): header(new node()) {}

        void GetGroup(int index, ElementType g[], int length) {
            for (int i = 0; i < length; i++)
                group[g[i]] = index;
        }

		void Enqueue(ElementType e) {
            node *insert_position = header;
            if (group.lower_bound(e) == group.end())
                while (insert_position->next) insert_position = insert_position->next;
            else
                while (insert_position->next && (group.lower_bound(insert_position->next->element) == group.end() || group[insert_position->next->element] != group[e])) insert_position = insert_position->next;
            insert_position->next = new node(e, insert_position->next);
		}

		void Dequeue() {
            node *tmp = header;
            header = header->next;
            delete tmp;
		}

		ElementType front() {
            if (!header->next)
                return (ElementType)NULL;
			return header->next->element;
		}
};

int main(int argc, char const *argv[]) {
	int NumGroup;
    char persons[26];
    LinkList<char> list;
	cin >> NumGroup;
	for (int group = 0; group < NumGroup; group++) {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> persons[i];
        list.GetGroup(group, persons, m);
	}
    string operation;
    while (cin >> operation) {
        if (operation == "ENQUEUE") {
            char person;
            cin >> person;
            list.Enqueue(person);
        }
        else if (operation == "DEQUEUE") {
			cout << list.front() << '\n';
            list.Dequeue();
        }
    }
	return 0;
}
