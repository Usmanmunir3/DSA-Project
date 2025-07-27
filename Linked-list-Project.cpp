#include <iostream>
#include <string>
using namespace std;

template <class T>
class Library {
private:
    struct Node {
        T id;
        T name;
        T author;
        Node *next;
    };

public:
    Node *head = nullptr;

    Library() : head(nullptr) {}

    ~Library() {
        Node *current = head;
        Node *next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void menu();
    void insertRecord(const T &id, const T &name, const T &author);
    void searchRecord();
    void updateRecord();
    void deleteRecord();
    void showAllRecords();
    void administration();
    void createStudentRecord();
    void displayAllStudents();
    void displaySpecificStudent();
    void modifyStudentRecord();
    void deleteStudentRecord();
    void createBook();
    void displayAllBooks();
    void displaySpecificBook();
    void modifyBookRecord();
    void deleteBookRecord();
    void sortRecords();
};

template <class T>
void Library<T>::insertRecord(const T &id, const T &name, const T &author) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->id == id || temp->name == name) return;
        temp = temp->next;
    }

    Node *newNode = new Node{ id, name, author, nullptr };

    if (head == nullptr || head->id > id) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *ptr = head;
        while (ptr->next != nullptr && ptr->next->id < id) {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

template <class T>
void Library<T>::searchRecord() {
    T searchId;
    cout << "\n Enter ID to Search: ";
    cin >> searchId;

    Node *ptr = head;
    while (ptr != nullptr) {
        if (ptr->id == searchId) {
            cout << "\n ID: " << ptr->id;
            cout << "\n Name: " << ptr->name;
            cout << "\n Author/Dept: " << ptr->author;
            return;
        }
        ptr = ptr->next;
    }
    cout << "\n Record not found.";
}

template <class T>
void Library<T>::updateRecord() {
    T updateId;
    cout << "\n Enter ID to Update: ";
    cin >> updateId;

    Node *ptr = head;
    while (ptr != nullptr) {
        if (ptr->id == updateId) {
            cout << "\n Enter New ID: ";
            cin >> ptr->id;
            cout << "\n Enter New Name: ";
            cin.ignore();
            getline(cin, ptr->name);
            cout << "\n Enter New Author/Department: ";
            getline(cin, ptr->author);
            cout << "\n Record Updated.";
            return;
        }
        ptr = ptr->next;
    }
    cout << "\n Record not found.";
}

template <class T>
void Library<T>::deleteRecord() {
    T deleteId;
    cout << "\n Enter ID to Delete: ";
    cin >> deleteId;

    if (head == nullptr) return;

    if (head->id == deleteId) {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "\n Record Deleted.";
        return;
    }

    Node *ptr = head;
    while (ptr->next != nullptr && ptr->next->id != deleteId) {
        ptr = ptr->next;
    }

    if (ptr->next == nullptr) {
        cout << "\n Record not found.";
        return;
    }

    Node *temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;
    cout << "\n Record Deleted.";
}

template <class T>
void Library<T>::showAllRecords() {
    Node *ptr = head;
    cout << "\n====================================";
    cout << "\n ID\t\tName\t\tAuthor/Dept";
    cout << "\n====================================";
    while (ptr != nullptr) {
        cout << "\n " << ptr->id << "\t\t" << ptr->name << "\t\t" << ptr->author;
        ptr = ptr->next;
    }
    cout << "\n====================================";
}

template <class T>
void Library<T>::createStudentRecord() {
    T studentId, studentName, studentDepartment;
    cout << "\n Enter Student ID: ";
    cin >> studentId;
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->id == studentId) return;
        temp = temp->next;
    }
    cout << "\n Enter Student Name: ";
    cin.ignore();
    getline(cin, studentName);
    cout << "\n Enter Student Department: ";
    getline(cin, studentDepartment);
    insertRecord(studentId, studentName, studentDepartment);
}

template <class T>
void Library<T>::displayAllStudents() {
    showAllRecords();
}

template <class T>
void Library<T>::displaySpecificStudent() {
    searchRecord();
}

template <class T>
void Library<T>::modifyStudentRecord() {
    updateRecord();
}

template <class T>
void Library<T>::deleteStudentRecord() {
    deleteRecord();
}

template <class T>
void Library<T>::createBook() {
    T bookId, bookName, bookAuthor;
    cout << "\n Enter Book ID: ";
    cin >> bookId;
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->id == bookId) return;
        temp = temp->next;
    }
    cout << "\n Enter Book Name: ";
    cin.ignore();
    getline(cin, bookName);
    cout << "\n Enter Book Author: ";
    getline(cin, bookAuthor);
    insertRecord(bookId, bookName, bookAuthor);
}

template <class T>
void Library<T>::displayAllBooks() {
    showAllRecords();
}

template <class T>
void Library<T>::displaySpecificBook() {
    searchRecord();
}

template <class T>
void Library<T>::modifyBookRecord() {
    updateRecord();
}

template <class T>
void Library<T>::deleteBookRecord() {
    deleteRecord();
}

template <class T>
void Library<T>::sortRecords() {
    if (head == nullptr || head->next == nullptr) return;

    bool swapped;
    Node *ptr;
    Node *last = nullptr;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->id > ptr->next->id) {
                T tempId = ptr->id;
                T tempName = ptr->name;
                T tempAuthor = ptr->author;

                ptr->id = ptr->next->id;
                ptr->name = ptr->next->name;
                ptr->author = ptr->next->author;

                ptr->next->id = tempId;
                ptr->next->name = tempName;
                ptr->next->author = tempAuthor;

                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

template <class T>
void Library<T>::administration() {
    int adminChoice;
    do {
        cout << "\n\n\t\tAdministration Menu";
        cout << "\n 1. Create Student Record";
        cout << "\n 2. Display All Students";
        cout << "\n 3. Display Specific Student";
        cout << "\n 4. Modify Student Record";
        cout << "\n 5. Delete Student Record";
        cout << "\n 6. Create Book";
        cout << "\n 7. Display All Books";
        cout << "\n 8. Display Specific Book";
        cout << "\n 9. Modify Book Record";
        cout << "\n 10. Delete Book Record";
        cout << "\n 11. Back to Main Menu";
        cout << "\n Enter Your Choice: ";
        cin >> adminChoice;

        switch (adminChoice) {
        case 1: createStudentRecord(); break;
        case 2: displayAllStudents(); break;
        case 3: displaySpecificStudent(); break;
        case 4: modifyStudentRecord(); break;
        case 5: deleteStudentRecord(); break;
        case 6: createBook(); break;
        case 7: displayAllBooks(); break;
        case 8: displaySpecificBook(); break;
        case 9: modifyBookRecord(); break;
        case 10: deleteBookRecord(); break;
        case 11: return;
        }
    } while (adminChoice != 11);
}

template <class T>
void Library<T>::menu() {
    int choice;
    do {
        cout << "\n\n\t\tLibrary Management System";
        cout << "\n 1. Insert New Record";
        cout << "\n 2. Search Record";
        cout << "\n 3. Update Record";
        cout << "\n 4. Delete Record";
        cout << "\n 5. Show All Records";
        cout << "\n 6. Administration";
        cout << "\n 7. Sort Records";
        cout << "\n 8. Exit";
        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            T id, name, author;
            cout << "\n Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "\n Enter Name: ";
            getline(cin, name);
            cout << "\n Enter Author/Department: ";
            getline(cin, author);
            insertRecord(id, name, author);
            break;
        }
        case 2: searchRecord(); break;
        case 3: updateRecord(); break;
        case 4: deleteRecord(); break;
        case 5: showAllRecords(); break;
        case 6: administration(); break;
        case 7: sortRecords(); break;
        case 8: break;
        default: break;
        }
    } while (choice != 8);
}

int main() {
    Library<string> l;

    l.insertRecord("101", "Chanakya Niti", "Ashwani Sharma");
    l.insertRecord("102", "Urdu Adab ka Safar", "Mustansar Hussain Tarar");
    l.insertRecord("103", "Lab Pe Aati Hai Dua Ban Ke Tamanna Meri", "Allama Iqbal");
    l.insertRecord("104", "Aangan", "Khadija Mastoor");
    l.insertRecord("105", "Toba Tek Singh", "Saadat Hasan Manto");
    l.insertRecord("106", "Alakh Nagri", "Mumtaz Mufti");
    l.insertRecord("107", "Moth Smoke", "Mohsin Hamid");
    l.insertRecord("108", "Purani Jeans", "Ali Haider");
    l.insertRecord("109", "Ishq Ka Ain", "Aleem-ul-Haq Haqqi");
    l.insertRecord("110", "Aag Ka Darya", "Qurratulain Hyder");
    l.insertRecord("111", "Udaas Naslain", "Abdullah Hussain");
    l.insertRecord("112", "Haveli", "Mushtaq Ahmed Yousufi");
    l.insertRecord("113", "Manto Ki Behtareen Kahanian", "Saadat Hasan Manto");
    l.insertRecord("114", "Devta", "Mohiuddin Nawab");
    l.insertRecord("115", "Gadariya", "Ashfaq Ahmed");
    l.insertRecord("116", "Shahab Nama", "Qudrat Ullah Shahab");
    l.insertRecord("117", "Mazhab Aur Science", "Syed Abul Ala Maududi");
    l.insertRecord("118", "Jannat Ke Pattay", "Nimra Ahmed");
    l.insertRecord("119", "Peer-e-Kamil", "Umera Ahmed");
    l.insertRecord("120", "Aab-e-Hayat", "Umera Ahmed");
    l.insertRecord("121", "Firdous-e-Iblees", "Inayat Ullah");
    l.insertRecord("122", "Zavia", "Ashfaq Ahmed");
    l.insertRecord("123", "Bano", "Razia Butt");
    l.insertRecord("124", "Hasil Ghaat", "Bano Qudsia");
    l.insertRecord("125", "Jungle Khanay", "Maulana Wahiduddin Khan");

    l.menu();

    return 0;
}