#include "../logic/controller.h"
#include <iostream>

int main() {
    Logic::SchoolController controller;
    int choice;

    while (true) {
        std::cout << "\n--- 选课系统 (终端版) ---" << std::endl;
        std::cout << "1. 查看课程  2. 安排排课  0. 退出" << std::endl;
        std::cout << "请选择: ";
        std::cin >> choice;

        if (choice == 1) {
            controller.showCourses();
        } else if (choice == 2) {
            int id, tid, cred; std::string name;
            std::cout << "输入课程ID,名称,教师ID,学分: ";
            std::cin >> id >> name >> tid >> cred;
            controller.arrangeTask(id, name, tid, cred);
        } else if (choice == 0) break;
    }
    return 0;
}
