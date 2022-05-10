package test.filter;

import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;

public class FilterDemo2 implements Filter {

    @Override
    public void destroy() {

    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse response, FilterChain filterChain) throws IOException, ServletException {
        HttpServletRequest req = (HttpServletRequest) servletRequest;
        HttpServletRequest res = (HttpServletRequest) response;

        System.out.println("1:" + req.getRequestURI());
        System.out.println("2:" + req.getRequestURL());
        System.out.println("3:" + req.getContextPath());
        System.out.println("4:" + req.getServletPath());

        String url = req.getRequestURL().toString();

        if (url.contains("LoginServlet")) {
            System.out.println("检测到url中有LoginServlet");
        }

        System.out.println("Here is the second Filter");
        filterChain.doFilter(servletRequest, response);
    }

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }
}
