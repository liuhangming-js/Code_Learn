package Impl;

import DBUtil.JDBCUtil;
import Dao.StudentDao;
import entity.Student;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class StudentDaoImpl implements StudentDao {
    public List<Student> getListAll(){
        List<Student> list = new ArrayList<Student>();
        try {
            Connection conn = JDBCUtil.getConnection();
            String sql = "select * from student";
            PreparedStatement ps = conn.prepareStatement(sql);
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                Student stu = new Student();
                stu.setName(rs.getString(1));
                stu.setSex(rs.getInt(2));
                stu.setAge(rs.getInt(3));
                list.add(stu);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return list;
    }
}
