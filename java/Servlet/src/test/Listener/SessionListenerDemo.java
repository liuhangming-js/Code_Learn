package test.Listener;

import javax.servlet.ServletContext;
import javax.servlet.annotation.WebListener;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

@WebListener
public class SessionListenerDemo implements HttpSessionListener {
    @Override
    public void sessionCreated(HttpSessionEvent sessionEvent) {
        ServletContext ctx = sessionEvent.getSession().getServletContext();
        System.out.println("刚创建的SessionID:" + sessionEvent.getSession().getId());

        Integer onlineCount = (Integer) ctx.getAttribute("OnlineCount");
        if (onlineCount == null) {
            onlineCount = 1;
        }else {
            int count = onlineCount.intValue();
            onlineCount = count + 1;
        }
        ctx.setAttribute("OnlineCount", onlineCount);
    }

    @Override
    public void sessionDestroyed(HttpSessionEvent sessionEvent) {
        ServletContext ctx = sessionEvent.getSession().getServletContext();
        System.out.println("刚销毁的SessionID:" + sessionEvent.getSession().getId());

        Integer onlineCount = (Integer) ctx.getAttribute("OnlineCount");
        if (onlineCount == null) {
            onlineCount = 1;
        }else {
            int count = onlineCount.intValue();
            onlineCount = count - 1;
        }
        ctx.setAttribute("OnlineCount", onlineCount);
    }
}
