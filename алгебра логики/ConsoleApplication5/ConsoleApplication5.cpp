#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

class Token {
public:
    char kind;        
    bool value;      
    Token(char ch)    
        :kind(ch), value(false) { }
    Token(char ch, bool val)     
        :kind(ch), value(val) { }
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream()
    :full(false), buffer(0)
{
}

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}
Token Token_stream::get()
{
    if (full) {       
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    

    switch (ch) {
    case ';':    
    case 'q':    
    case '(': case ')': case '!': case '&': case '|': case '^':
        return Token(ch);        
    case '0': case '1':
    {
        cin.putback(ch);        
        bool val;
        cin >> val;              
        return Token('8', val);   
    }
    default:
        error("Bad token");
    }
}

Token_stream ts;
bool expression();

bool primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '!': {ts.putback(t);return 0;}
	case '(':    
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '8':
		return t.value;
	case 'q': {ts.putback(t); return 0; }

	default:
		error("primary expected");
	}
}

bool fuckt() {
	bool left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind)
		{
		case '!': {
			if (primary() == 1) left = 0;
			else left = 1;
			t = ts.get();break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

bool three() {
	bool left = fuckt();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '&': {
			left &= fuckt();
			t = ts.get(); break; }
		default:
			ts.putback(t);
			return left;
		}
	}
}

bool term()
{
	bool left = three();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '^': {
			left ^= three();
			t = ts.get(); break; }
		default:
			ts.putback(t);
			return left;
		}
	}
}

bool expression()
{
	bool left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '|': {
			left |= term();
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}


int main()
try
{
    setlocale(LC_ALL, "Russian");
    bool val;
    while (cin) {
        Token t = ts.get();
        if (t.kind == 'q') break; 
        if (t.kind == ';')        
            cout << "=" << val << '\n';
        else
            ts.putback(t);
		val = expression();
    }
    keep_window_open();
}
catch (exception & e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
