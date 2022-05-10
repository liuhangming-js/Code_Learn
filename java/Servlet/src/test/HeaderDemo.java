package test;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

@WebServlet(name = "HeaderDemo", urlPatterns = {"/HeaderDemo"}, initParams = {@WebInitParam(name = "name", value = "Johnson")})
public class HeaderDemo extends HttpServlet {
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        res.setContentType("text/html");
        PrintWriter out = res.getWriter();
        Enumeration hnames = req.getHeaderNames();

        out.println("<H3>The request headers are:</H3>");
        while (hnames.hasMoreElements()) {
            String hname = (String) hnames.nextElement();

            Enumeration hvalues = req.getHeaders(hname);
            out.println("<BR>");

            if (hvalues != null) {
                while (hvalues.hasMoreElements()) {
                    String hvalue = (String) hvalues.nextElement();
                    out.println(hname + ":" + hvalue);
                }
            }
        }

        ServletConfig config = getServletConfig();
        String name = config.getInitParameter("name");
        out.append(name);
    }
}
