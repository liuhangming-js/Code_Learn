package test.JSPTags;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import java.io.IOException;

public class WelcomeTag extends TagSupport {
    @Override
    public int doStartTag() throws JspException {
        JspWriter out = pageContext.getOut();
        try {
            out.println("Welcome");
        } catch (IOException e) {
            e.printStackTrace();
        }
        return  SKIP_BODY;
    }

    @Override
    public int doAfterBody() throws JspException {
        System.out.println("doAfterBody");

        return 2;
    }

    @Override
    public int doEndTag() throws JspException {
        System.out.println("doEndTag");

        return EVAL_PAGE;
    }
}
