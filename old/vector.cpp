#include <iostream>

using namespace std;

template <typename T>
class vector {
public:
    vector() {
        m_size = 0;
        m_capacity = 4;
        m_data = new T[m_capacity];
    }

    size_t size() {
        return m_size;
    }

    void push(T item) {
        ensure_capacity(m_size + 1);
        m_data[m_size++] = item;
    }

    void insert(size_t index, T item) {
        if (index >= m_size + 1) throw std::out_of_range("index out of range");
        ensure_capacity(m_size + 1);
        for (size_t i = m_size - 1; i >= index; i--) {
            m_data[i + 1] = m_data[i];
        }
        m_data[index] = item;
        m_size++;
    }

    T pop() {
        if (m_size == 0) throw std::out_of_range("index out of range");
        return m_data[--m_size];
    }

    T erase(size_t index) {
        if (index >= m_size) throw std::out_of_range("index out of range");
        T res = m_data[index];
        for (size_t i = index; i < m_size; i++) {
            m_data[i] = m_data[i + 1];
        }
        m_size--;
        return res;
    }

    T operator[](size_t i) {
        if (i >= m_size) throw std::out_of_range("index out of range");
        return m_data[i];
    }

private:
    size_t m_capacity;
    size_t m_size;
    T *m_data;

    void expand(size_t capacity) {
        T *resized = new T[capacity];
        for (size_t i = 0; i < m_size; i++) {
            resized[i] = m_data[i];
        }
        delete m_data;
        m_data = resized;
    }

    void ensure_capacity(size_t capacity) {
        if (capacity <= m_capacity) return;
        while (capacity > m_capacity) {
            m_capacity *= 2;
        }
        expand(m_capacity);
    }
};

int main() {
    vector<int> v;

    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        v.push(i);
    }
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << v.pop() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    v.insert(2, 5);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << v.erase(4) << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}