package service;

import Dao.StudentDao;
import Impl.StudentDaoImpl;
import entity.Student;

import java.util.List;

public class StudentService {
    public List<Student> getListAll() {
        StudentDao stuDao = new StudentDaoImpl();
        List list = stuDao.getListAll();
        return list;
    }
}
