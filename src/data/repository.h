#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../domain/entity.h"
#include <pqxx/pqxx> 
#include <vector>
#include <iostream>

namespace Data {
    class CourseRepository {
    private:
        std::string conn_str = "host=localhost dbname=DBname user=gaohaoran password=password";
    public:
        // 获取所有课程
        std::vector<Domain::Course> findAll() {
            std::vector<Domain::Course> list;
            try {
                pqxx::connection c(conn_str);
                pqxx::work w(c);
                pqxx::result r = w.exec("SELECT id, name, teacher_id, credits FROM courses");
                for (auto row : r) {
                    list.push_back({row[0].as<int>(), row[1].as<std::string>(), row[2].as<int>(), row[3].as<int>()});
                }
            } catch (...) {}
            return list;
        }

        // 保存新课程 (排课)
        void save(const Domain::Course& c) {
            pqxx::connection conn(conn_str);
            pqxx::work w(conn);
            conn.prepare("insert", "INSERT INTO courses VALUES ($1, $2, $3, $4)");
            w.exec_prepared("insert", c.id, c.name, c.teacherId, c.credits);
            w.commit();
        }
    };
}

#endif

