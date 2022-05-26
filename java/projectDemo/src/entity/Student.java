package entity;

public class Student {
    String name;
    int sex;
    int age;

    public int getAge() {
        return age;
    }

    public int getSex() {
        return sex;
    }

    public String getName() {
        return name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSex(int sex) {
        this.sex = sex;
    }
}
