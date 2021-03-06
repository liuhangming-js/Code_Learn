package servlet;

import entity.Student;
import service.StudentService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/listStudent.go")
public class StudentServlet extends HttpServlet {
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        StudentService studentService = new StudentService();
        List list = studentService.getListAll();
        req.setAttribute("list", list);
        req.getRequestDispatcher("./admin/demo_list.jsp").forward(req, resp);
    }
}
