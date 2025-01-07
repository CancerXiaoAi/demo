using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication3
{
    public partial class index : System.Web.UI.Page
    {
        static int bananaSum = 0;
        static int appleSum = 0;
        static int pairSum = 0;
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void add(object sender, EventArgs e)
        {
            Button button = sender as Button;
            if (button.ID == "banana")
            {
                bananaSum++;
            }

                if (button.ID == "apple")
                {
                    appleSum++;
                }

            if (button.ID == "pair")
            {
                pairSum++;
            }

            Response.Write("香蕉买了 " + bananaSum + " 个<br>");
            Response.Write("苹果买了 " + appleSum + " 个<br>");
            Response.Write("梨买了 " + pairSum + " 个<br>");
        }

        protected void submit(object sender, EventArgs e)
        {
            Dictionary<String, int> fruit = new Dictionary<string, int>();
            int bananaPrice = bananaSum * 10;
            int applePrice = appleSum * 5;
            int pairPrice = pairSum * 5;

            fruit.Add("banana", bananaPrice);
            fruit.Add("apple", applePrice);
            fruit.Add("pair", pairPrice);
            // craete Table first
            createTabel();
            foreach (var item in fruit)
            {
                String key = item.Key;
                int value = item.Value;
                saveToDB(key, value);
            }
        }

        private void createTabel()
        {
            String tableName = "test";
            String connStr = "Data Source=10.145.152.185;Database=xujg-schooldb;User Id=user-xujg;Password=xu-2231;Encrypt=false";
            SqlConnection conn = new SqlConnection(connStr);
            conn.Open();
            // create a table
            SqlCommand createTable = new SqlCommand("create table " + tableName + "(" +
                "id varchar(30)," +
                "name varchar(20)," +
                "price int" +
                ")", conn);
            createTable.ExecuteNonQuery();
        }
        private void saveToDB(String name, int price)
        {
            // define some database connection information
            String tableName = "test";
            String connStr = "Data Source=10.145.152.185;Database=xujg-schooldb;User Id=user-xujg;Password=xu-2231;Encrypt=false";
            SqlConnection conn= new SqlConnection(connStr);
            conn.Open();

            // save to database
            String now = DateTime.Now.ToString();
            SqlCommand saveData = new SqlCommand("insert into " + tableName + " values(\'"+now+"\', \'"+name+"\', "+price+")", conn);
            saveData.ExecuteNonQuery();
        }

        protected void clean(object sender, EventArgs e)
        {
            bananaSum = 0;
            appleSum = 0;
            pairSum = 0;
            Response.Write("香蕉买了 " + bananaSum + " 个<br>");
            Response.Write("苹果买了 " + appleSum + " 个<br>");
            Response.Write("梨买了 " + pairSum + " 个<br>");
        }
    }
}