package niit;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class JDBCUtil {
	
	private static String url = "jdbc:mysql://localhost:3306/test?useSSL=false&characterEncoding=UTF-8&serverTimezone=UTC";
	private static String user = "root";
	private static String pwd = "123456";
	private static String driverName = "com.mysql.cj.jdbc.Driver";
	// 数据库连接对象
	private static Connection conn = null;

	/**
	 * 获取数据库连接对象
	 * @return
	 */
	public static Connection getConnection() {
		try {
			Class.forName(driverName);// 加载驱动
			conn = DriverManager.getConnection(url, user, pwd);// 获得数据库连接对象
			System.err.println("-----日志信息：数据库连接成功");
		} catch (Exception e) {
			System.err.println("-----日志信息：数据库连接失败");
			e.printStackTrace();
		}
		return conn;
	}

	public static void close(Connection conn) {
		if (conn != null) {
			try {
				conn.close();// 关闭资源
				System.err.println("-----日志信息：数据库已断开连接");
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
	//测试数据库是否能连接成功
	public static void main(String[] args) {
		JDBCUtil.getConnection();
	}
}
