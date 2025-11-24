#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    string type;
    int level;
};

const int MAX_SIZE = 100;
Item items[MAX_SIZE];
int count = 0;

void add(string n, string t, int l) {
    if (count < MAX_SIZE) {
        items[count] = {n, t, l};
        count++;
        cout << "Добавлен: " << n << endl;
    } else {
        cout << "Переполнение!" << endl;
    }
}

void remove(string n) {
    for (int i = 0; i < count; i++) {
        if (items[i].name == n) {
            for (int j = i; j < count - 1; j++) {
                items[j] = items[j + 1];
            }
            count--;
            cout << "Удален: " << n << endl;
            return;
        }
    }
    cout << "Не найден: " << n << endl;
}

void show() {
    cout << "\n--- ИНВЕНТАРЬ (" << count << ") ---" << endl;
    for (int i = 0; i < count; i++) {
        cout << items[i].name << " | " 
             << items[i].type << " | " 
             << items[i].level << endl;
    }
}

void sortLevel() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (items[j].level > items[j + 1].level) {
                swap(items[j], items[j + 1]);
            }
        }
    }
    cout << "Сортировка завершена" << endl;
}

void filter(string t) {
    cout << "\n--- " << t << " ---" << endl;
    for (int i = 0; i < count; i++) {
        if (items[i].type == t) {
            cout << items[i].name << " | " << items[i].level << endl;
        }
    }
}

int main() {
    add("Меч", "оружие", 10);
    add("Щит", "броня", 5);
    add("Зелье", "зелье", 1);

    while (true) {
        cout << "\n1.Добавить 2.Удалить 3.Показать 4.Сортировать 5.Фильтр 0.Выход\nВыбор: ";
        int cmd;
        cin >> cmd;
        
        if (cmd == 0) break;
        
        if (cmd == 1) {
            string n, t;
            int l;
            cout << "Название Тип Уровень: ";
            cin >> n >> t >> l;
            add(n, t, l);
        }
        else if (cmd == 2) {
            string n;
            cout << "Что удалить: ";
            cin >> n;
            remove(n);
        }
        else if (cmd == 3) show();
        else if (cmd == 4) { sortLevel(); show(); }
        else if (cmd == 5) {
            string t;
            cout << "Тип: ";
            cin >> t;
            filter(t);
        }
    }
    return 0;
}