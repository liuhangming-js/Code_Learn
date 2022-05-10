package test;


import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;


@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		response.setCharacterEncoding("utf-8");
		String name=request.getParameter("name");
		String pwd=request.getParameter("password");
		//String hiddenData=request.getParameter("hiddenData");//隐藏表单

//		//create cookie
//		Cookie cookie = new Cookie("username", "Johnson");
//		cookie.setMaxAge(30);//存活30秒
//
//		response.addCookie(cookie);

		HttpSession httpSession = request.getSession();
		System.out.println(httpSession.getId());
		httpSession.setAttribute("name", name);
		httpSession.setAttribute("password", pwd);
		response.sendRedirect("IndexServlet");
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request,response);
	}

}
