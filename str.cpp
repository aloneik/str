#include <iostream>
#include <cstddef>
#include <cstring>

using namespace std;

struct String {
	String(const char *st = "") {
		this->str = new char[strlen(st) + 1];
		this->size = strlen(st);
		for (int i = 0; i < size; i++) {
			this->str[i] = st[i];
		}
	}
	//String(size_t n, char c);

	String(const String &other) {
		this->str = new char[other.size + 1];
		this->size = other.size;
		for (int i = 0; i < size; i++) {
			this->str[i] = other.str[i];
		}
	}

	~String() {
		delete[] str;
	}
	//String &operator=(const String &other);

	//void append(const String &other);
	class St {
	public:
		St(String & st, int j) {
			this->size = st.size;
			this->str = new char[size + 1];
			for (int i = 0; i < size; i++) {
				this->str[i] = st.str[i];
			}
			perv = j;
		}
		St(const char * st, int j) {
			this->str = new char[strlen(st) + 1];
			this->size = strlen(st);
			for (int i = 0; i < size; i++) {
				this->str[i] = st[i];
			}
			perv = j;
		}
		~St() {
			delete[] str;
		}


		String operator[](int i) const {
			char * stn = new char[i - perv + 1];
			for (int k = 0; k < i - perv; k++) {
				stn[k] = this->str[k];
				cout << k;
			}
			stn[i - perv] = '\0';
			String newStr(stn);
			delete[] stn;
			return newStr;
		}
		size_t size;
		char *str;
		int perv;
	};

	St operator[](int i) const {
		char * stn = new char[this->size - i];
		strcpy(stn, (this->str + i));
		St newStr(stn, i);
		cout << stn << endl;
		delete[] stn;
		return newStr;
	}

	size_t size;
	char *str;
};