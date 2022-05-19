package test.Beans;

public class Student {
    private Integer sid;
    private String sname, email, sex;

    public Student() {
    }
    public Student(String sname, String email, String sex) {
        this.sname = sname;
        this.email = email;
        this.sex = sex;
    }

    public Integer getSid() {
        return sid;
    }

    public String getEmail() {
        return email;
    }

    public String getSex() {
        return sex;
    }

    public String getSname() {
        return sname;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void setSid(Integer sid) {
        this.sid = sid;
    }

    public void setSname(String sname) {
        this.sname = sname;
    }
}
