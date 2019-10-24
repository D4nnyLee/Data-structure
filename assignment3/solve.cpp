#include <iostream>
using namespace std;

class Queue {
	public:
		Queue(int n, char list[26][26]): head(new node) {
			for (int i = 0; i < n; i++)
                group[i] = '\x00';
			for (int i = 0; i < n; i++)
				for (int j = 0; j < 26 && list[i][j]; j++)
                    group[list[i][j] - 'A'] = list[i][0];
		}
		void EnQueue(char newcomer) {
            // find the position to insert
			node *tmp = head;
			while (tmp->next && (group[newcomer - 'A'] == '\x00' || group[tmp->next->id] != group[newcomer - 'A']))
                tmp = tmp->next;
            // insert new node
            tmp->next = new node(newcomer - 'A', tmp->next);
		}
		char DeQueue() {
            if (head->next == NULL)
                return 0;
            node *tmp = head;
            head = head->next;
            delete tmp;
            return head->id + 'A';
		}
	private:
		struct node {
            int id;
			node *next;
            node (): id(0), next(NULL) {}
            node (int _id, node *_next): id(_id), next(_next) {}
		};
		node *head;
        char group[26];
};

int main(int argc, char const *argv[]) {
	char list[26][26];
	int n, m;
	while (cin >> n) {
		// initialize
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 26; j++)
				list[i][j] = 0;
		// get the list of friend
		for (int i = 0; i < n && cin >> m; i++)
			for (int j = 0; j < m && cin >> list[i][j]; j++);
		Queue q(n, list);
        string operation;
        char newcomer;
        while (cin >> operation) {
            if (operation == "ENQUEUE" && cin >> newcomer)
                q.EnQueue(newcomer);
            else if (operation == "DEQUEUE")
                cout << q.DeQueue() << endl;
        }
	}
	return 0;
}
