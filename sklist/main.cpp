#include "ArrayList.h"

int main() {
    ArrayList<int, std::string> list;

    // 测试插入操作
    list.insert(1, "One");
    list.insert(2, "Two");
    list.insert(3, "Three");

    // 测试搜索操作
    std::string value;
    if (list.search(2, value)) {
        std::cout << "Found: " << value << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    // 测试删除操作
    list.delete_key(2);

    // 再次测试搜索操作
    if (list.search(2, value)) {
        std::cout << "Found: " << value << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}