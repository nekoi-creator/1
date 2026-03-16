#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

namespace Domain {
    // 课程实体
    struct Course {
        int id;
        std::string name;
        int teacherId;
        int credits;
    };

    // 学生实体
    struct Student {
        int id;
        std::string name;
    };

    // 成绩实体
    struct Grade {
        int studentId;
        int courseId;
        float score;
    };
}

#endif
