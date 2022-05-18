package test;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;


@WebServlet("/IndexServlet")
public class IndexServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		response.setCharacterEncoding("utf-8");

//		String hiddenData=request.getParameter("hiddenData");
//		Cookie[] cookie = request.getCookies();
//		if (cookie != null) {
//			for (Cookie item : cookie) {
//				if ("username".equals(item.getName())) {
//					String value = item.getValue();
//					response.getWriter().append(value);
//				}
//			}
//		}else {
//			response.sendRedirect("404.html");
//		}

		HttpSession httpSession = request.getSession();
		System.out.println(httpSession.getId());
		String name = (String) httpSession.getAttribute("name");
		String password = (String) httpSession.getAttribute("password");

		response.getWriter().append("Your name is: ").append(name).append("<br/>").append("Your password is: ").append(password);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
