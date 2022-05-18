package test;

import javax.servlet.*;
import javax.servlet.http.HttpServlet;
import java.io.IOException;

public class LifeCycleServlet extends HttpServlet {
    public void init(ServletConfig config) {
        System.out.println("init()方法被调用...");
        String name = config.getInitParameter("name");
        System.out.println(name);
        //获取到ServletContext
        ServletContext sc = config.getServletContext();
        //获取ServletContext级别的全局容器参数
        String contextvalue = sc.getInitParameter("contextName");
        System.out.println(contextvalue);
    }

    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        System.out.println("service调用");
    }

    public void destroy() {
        System.out.println("destroy调用");
    }
}
