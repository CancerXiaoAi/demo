using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Data.SqlClient;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace luoyq
{
    public partial class apple : System.Web.UI.Page
    {
        static int applesum = 0;
        int myindexgoods = 0;
        string connstr = "data source=10.145.152.185;database=pan-schooldb;user id=user-panj2;password=pan-2231;encrypt=false;";
        SqlConnection conn;
        static int[] goods = {0,0,0};
       

        string constr, comdtext, msg;
       
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void add(object sender, EventArgs e)

        {
             
            Button button = sender as Button;
            if (button.ID == "apple2") goods[0]++;
            Response.Write(goods[0]);

        }
        protected void save(object sender, EventArgs e)
        {
            int curIndex = 1;
            RadioButtonList myradiolist = null;
            SqlConnection myconnl = new SqlConnection(connstr);
            myconnl.Open();
            SqlCommand judge = new SqlCommand("select * from INFORMATION_SCHEMA.tables where table_name=\'furit8\'", myconnl);
            SqlDataReader reader5 = judge.ExecuteReader();
            
            if (!reader5.Read())
            {
                reader5.Close();
                SqlCommand cmd1 = new SqlCommand("create table furit9(id char(10),name char(20),info char(4))", myconnl);
                SqlDataReader read1 = cmd1.ExecuteReader();
                read1.Close();

            }
            else reader5.Close();

            SqlConnection conn = new SqlConnection(connstr);
            conn.Open();
           
            Table curTable = (Table)FindControl("MYTABLE");
            Response.Write(curTable.Rows.Count);
            SqlConnection myconn0 = new SqlConnection(connstr);
            myconn0.Open();
            myindexgoods = 0;
            int myflag = 0;
                

            foreach (TableRow curRow in curTable.Rows)
            {
                if (curIndex > 0)

                {
                    myradiolist = (RadioButtonList)FindControl("radioList" + curIndex.ToString());
                    SqlCommand cmd2 = new SqlCommand("insert into furit8(id,crice,sum) values(" + "\'" + curRow.Cells[0].Text + "\'" + "," + "\'" + curRow.Cells[1].Text + "\'" + "," + "\'" + goods[myindexgoods].ToString() + "\'" + ")", myconn0);
                    myflag = cmd2.ExecuteNonQuery();
                    Response.Write(curRow.Cells[0].Text);
                    myindexgoods++;

                }

            }
            goods[0] = 0;
            goods[1] = 0;
            conn.Close();
            myconn0.Close();
        }
    }
}