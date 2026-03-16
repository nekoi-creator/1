#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../data/repository.h"
#include <iostream>

namespace Logic {
    class SchoolController {
    private:
        Data::CourseRepository courseRepo;
    public:
        // 业务：安排教学任务
        void arrangeTask(int id, std::string name, int tid, int cred) {
            Domain::Course c = {id, name, tid, cred};
            courseRepo.save(c);
            std::cout << "系统：教学任务已成功录入数据库。" << std::endl;
        }

        // 业务：查询可选课程
        void showCourses() {
            auto courses = courseRepo.findAll();
            for (const auto& c : courses) {
                std::cout << "ID:" << c.id << " | 课程:" << c.name << " | 学分:" << c.credits << std::endl;
            }
        }
    };
}

#endif

