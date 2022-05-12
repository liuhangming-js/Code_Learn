package test.JSPTags;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.TagSupport;
import java.io.IOException;

public class WelcomeTag extends TagSupport {

    private int num;

    public void setNum(int num) {
        this.num = num;
    }

    public int doStartTag() throws JspException {
        JspWriter out = pageContext.getOut();
        try {
            out.println("Welcome==="+ num * num);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return EVAL_BODY_INCLUDE;
    }

    public int doAfterBody() throws JspException {
        System.out.println("doAfterBody");

        return SKIP_BODY;
    }

    public int doEndTag() throws JspException {
        System.out.println("doEndTag");

        return SKIP_PAGE;
    }
}
