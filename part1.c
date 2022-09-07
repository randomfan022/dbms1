STUDENT LIBRARY DATABASE

//creation and insertion

create database student_library;

use student_library;

create table student (sno int primary key, sname varchar(20));

create table membership (mno int primary key, sno int,foreign key(sno) references student(sno));

create table book(bno int primary key, bname varchar(20), author varchar(20));

create table iss_rec (ino int primary key,date date,mno int,foreign key(mno) references membership(mno), bno int, foreign key (bno) references book(bno));

insert into student(sno, sname) values (1,"Ajeet"),(2,"Radhika"),(3,"Jay"),(4,"Ashish"),(5,"Deepika"),(6,"Preeti"),(7,"Raman"),(8,"Ashok"),(9,"Vedant"),(10,"Tanmoy");

insert into membership (mno, sno) values (101,1),(102,2),(103,3),(104,4),(105,5),(106,6);

insert into book (bno , bname, author) values (201,"JAVA","R.Sharma"),(202,"OS","A.P.Leach"),(203,"DBMS","S.Ramesh"),(204,"Maths","Dr S.K.C"),(205,"DAA","M.S. Rao");

insert into iss_rec(ino,date,mno,bno) values (301,"2020-08-03",101,201),(302,"2022-09-05",101,202),(303,"2021-08-04",101,205),(304,"2022-09-05",102,202),(305,"2021-08-22",102,204),(306,"2020-07-23",102,201),(307,"2019-09-09",103,201),(308,"2022-09-21",104,203),(309,"2022-09-05",105,202),(310,"2022-09-06",105,203),(311,"2022-09-07",105,204),(312,"2022-09-05",104,205);

//query 1

select s.sname,s.sno,m.mno from student s,membership m where s.sno=m.sno;

//query 2

select s.sname,b.bname,i.date from student s,book b,membership m,iss_rec i where s.sno=m.sno and i.mno=m.mno and i.bno=b.bno and i.date="2022-09-05";

//query 3

select s.sname,count(*) from student s,membership m,book b, iss_rec i where s.sno=m.sno and m.mno=i.mno and b.bno=i.bno group by (s.sname);

//query 4

select s.sname,b.bname from student s,membership m,book b, iss_rec i where s.sno=m.sno and m.mno=i.mno and b.bno=i.bno and s.sno=5;

//query 5

create view list as (select i.ino,i.date,s.sname,b.bname from student s,book b,membership m, iss_rec i where s.sno=m.sno and b.bno=i.bno and m.mno=i.mno);

select * from list;
//creation of tables

create database project;

use project;

create table student(roll int primary key,name varchar(20),sem int,degree varchar(10),contact varchar(10),gno int);

create table guide(gname varchar(20),gno int primary key,research varchar(20),contact varchar(10),email varchar(20));

create table project(pno int primary key,title varchar(20),area varchar(20), start date,gno int);

create table grp(grp_code int, roll int);

create table proj_grp(grp_code int primary key, pno int, num int);


//altering tables to add foreign key constraint

alter table student add constraint guide foreign key(gno) references guide(gno) on update cascade on delete cascade;

alter table project add constraint guide_2 foreign key(gno) references guide (gno) on update cascade on delete cascade;

alter table grp add constraint roll foreign key(roll) references student(roll) on update cascade on delete cascade;

alter table grp add constraint grpcode foreign key(grp_code) references proj_grp(grp_code) on update cascade on delete cascade;

alter table grp add constraint roll_2 foreign key(roll) references student(roll) on update cascade on delete cascade;

alter table proj_grp add constraint pno foreign key(pno) references project(pno) on update cascade on delete cascade;

//inserting values 

insert into guide(gname,gno,research,contact,email) values ("Ajeet Singh",101,"ML/AI","9876543745","aj@email.com"),("Suddha Sharma",102,"WebD","9076594038","s@email.com"),("Anuradha",103,"IoT","9756484937","an@email.com"),("Alok",104,"App","9856432947","al@email.com"),("Preeti",105,"Cyber","7856392047","p@email.com");

insert into student (roll,name,sem,degree,contact,gno) values (1,"Radhika",4,"B.E","7684086805",101),(2,"Jaya",2,"B.E","6785937590",101),(3,"Aman",6,"B.E.","6573945678",101),(4,"Ritesh",4,"B.E","7684077896",101),(5,"Sumit",6,"B.E","9547675466",102),(6,"Suresh",8,"B.E","8975766789",102),(7,"Ritika",6,"B.E","7895665784",103),(8,"Umang",6,"B.E","8756478897",103),(9,"Anika",2,"B.E","8976889576",104),(10,"Himanshu",4,"B.E.","8795675844",104),(11,"Deepika",6,"B.E.","7869507768",105),(12,"Smita",6,"B.E","9088677684",105),(13,"Supriti",8,"B.E","7896748876",105);

insert into project (pno,title,area,start,gno) values (201,"App1","App","2022-09-08",104),(202,"App2","App","2022-03-02",104),(203,"Site1","WebD","2020-09-23",102),(204,"ML","ML/AI","2020-02-01",101),(205,"Site2","WebD","2020-05-04",102),(206,"MPs","IoT","2021-03-23",103),(207,"MicroComp","IoT","2021-09-23",103),(208,"Secur","Cyber","2020-03-23",105);

insert into proj_grp(grp_code, pno,num) values (301,201,3),(302,202,3),(303,203,2),(304,204,3),(305,205,4);

insert into grp(grp_code,roll) values (301,1),(301,2),(301,3),(302,4),(302,5),(302,6),(303,2),(303,6),(304,7),(304,8),(304,1),(305,9),(305,12),(305,4),(305,5);

//query 1

select g.gname,count(*) from guide g,project p,proj_grp pg where pg.pno=p.pno and p.gno=g.gno group by (g.gno) having count(*)>=2;

//query 2

select p.pno,p.title,g.gname from project p,guide g where p.gno=g.gno and g.research="App";

//query 3

update student s, guide g set g.gno=106, g.gname="Ram",g.research="Cyber",g.contact="7896578868",g.email="r@gmail.com" where s.roll=13 and s.gno=g.gno;

//query 4

 update guide g, project p set g.gno=110, g.gname="Fahad",g.research="ML/AI", g.contact="6785935678",g.email="f@gmail.com" where p.gno=g.gno and g.gno=104;

//query 5

create view student_project as (select s.name,p.pno,g.gname from student s,guide g, project p where g.gno=p.gno and s.gno=g.gno and s.gno=p.gno);



//creation and insertion

create database airline;

create table flights(flno int primary key,fromm varchar(20),too varchar(20),distance int,departs time,arrives time,price int);

create table aircraft (aid int primary key,aname varchar(20), cruising_range int);

create table employees(eid int primary key, ename varchar(20),salary int);

create table certified (eid int,foreign key(eid) references employees(eid),aid int,foreign key(aid) references aircraft(aid));

insert into flights values(1,"Bangalore","Mumbai",20000,"08:30:00","11:30:00",2300);
insert into flights values(2,"Mumbai","Bangalore",20000,"08:30:00","11:30:00",2000);
insert into flights values(3,"Bangalore","Udaipur",80000,"09:30:00","12:30:00",6000);
insert into flights values(4,"Bangalore","Jaipur",80000,"10:30:00","01:30:00",8000);
insert into flights values(5,"Bangalore","Ranchi",60000,"10:00:00","12:00:00",7558);
insert into flights values(6,"Ranchi","Bangalore",60000,"10:00:00","12:00:00",6000);
insert into flights values(7,"Mumbai","Delhi",29000,"11:00:00","12:00:00",5467);
insert into flights values(8,"Bangalore","Mumbai",20000,"08:30:00","11:30:00",2000);

insert into aircraft (aid,aname,cruising_range) values (101,"Boeing111",26000),(102,"Boeing112",21500),(103,"Boeing",25000),(104,"Boeing123",23000),(105,"Boeing456",30000);

insert into employees (eid,ename,salary) values (201,"Ajay",50000),(202,"Anika",45000),(203,"Raman",48000),(204,"Samarth",56000);
insert into employees values(205,"Amit",1500);

insert into certified (eid,aid) values (201,101),(201,102),(201,103),(202,104),(202,105),(203,102),(203,103),(203,105),(204,101);

//query 1

select a.aname,a.aid from aircraft a,employees e, certified c where a.aid=c.aid and e.eid=c.eid and e.salary>=50000;

//query 2

select e.eid,e.ename,count(*),max(a.cruising_range) from employees e,certified c,aircraft a where a.aid=c.aid and c.eid=e.eid group by(e.eid) having count(*)>=3;

//query 3

select e.eid,e.ename from employees e where e.salary<(select min(f.price) from flights f );

//query 4

select e.eid,e.ename from employees e where e.salary<(select min(f.price) from flights f where f.fromm="Bangalore" and f.too="Mumbai");

//query 5

select max(e.salary) from employees e where e.salary not in(select max(e.salary) from employees e);

//query 6

create view list as (select e.eid,e.ename,a.aid, a.aname from employees e ,aircraft a,certified c where a.aid=c.aid and e.eid=c.eid);

select * from list;

//creation and insertion

create database airline;

create table flights(flno int primary key,fromm varchar(20),too varchar(20),distance int,departs time,arrives time,price int);

create table aircraft (aid int primary key,aname varchar(20), cruising_range int);

create table employees(eid int primary key, ename varchar(20),salary int);

create table certified (eid int,foreign key(eid) references employees(eid),aid int,foreign key(aid) references aircraft(aid));

insert into flights values(1,"Bangalore","Mumbai",20000,"08:30:00","11:30:00",2300);
insert into flights values(2,"Mumbai","Bangalore",20000,"08:30:00","11:30:00",2000);
insert into flights values(3,"Bangalore","Udaipur",80000,"09:30:00","12:30:00",6000);
insert into flights values(4,"Bangalore","Jaipur",80000,"10:30:00","01:30:00",8000);
insert into flights values(5,"Bangalore","Ranchi",60000,"10:00:00","12:00:00",7558);
insert into flights values(6,"Ranchi","Bangalore",60000,"10:00:00","12:00:00",6000);
insert into flights values(7,"Mumbai","Delhi",29000,"11:00:00","12:00:00",5467);
insert into flights values(8,"Bangalore","Mumbai",20000,"08:30:00","11:30:00",2000);

insert into aircraft (aid,aname,cruising_range) values (101,"Boeing111",26000),(102,"Boeing112",21500),(103,"Boeing",25000),(104,"Boeing123",23000),(105,"Boeing456",30000);

insert into employees (eid,ename,salary) values (201,"Ajay",50000),(202,"Anika",45000),(203,"Raman",48000),(204,"Samarth",56000);
insert into employees values(205,"Amit",1500);

insert into certified (eid,aid) values (201,101),(201,102),(201,103),(202,104),(202,105),(203,102),(203,103),(203,105),(204,101);

//query 1

select a.aname,a.aid from aircraft a,employees e, certified c where a.aid=c.aid and e.eid=c.eid and e.salary>=50000;

//query 2

select e.eid,e.ename,count(*),max(a.cruising_range) from employees e,certified c,aircraft a where a.aid=c.aid and c.eid=e.eid group by(e.eid) having count(*)>=3;

//query 3

select e.eid,e.ename from employees e where e.salary<(select min(f.price) from flights f );

//query 4

select e.eid,e.ename from employees e where e.salary<(select min(f.price) from flights f where f.fromm="Bangalore" and f.too="Mumbai");

//query 5

select max(e.salary) from employees e where e.salary not in(select max(e.salary) from employees e);

//query 6

create view list as (select e.eid,e.ename,a.aid, a.aname from employees e ,aircraft a,certified c where a.aid=c.aid and e.eid=c.eid);

select * from list;

//creation and insertion

create database airline;

create table flights(flno int primary key,fromm varchar(20),too varchar(20),distance int,departs time,arrives time,price int);

create table aircraft (aid int primary key,aname varchar(20), cruising_range int);

create table employees(eid int primary key, ename varchar(20),salary int);

create table certified (eid int,foreign key(eid) references employees(eid),aid int,foreign key(aid) references aircraft(aid));

insert into flights values(1,"Bangalore","Mumbai",20000,"08:30:00","11:30:00",2300);
insert into flights values(2,"Mumbai","Bangalore",20000,"08:30:00","11:30:00",2000);
insert into flights values(3,"Bangalore","Udaipur",80000,"09:30:00","12:30:00",6000);
insert into flights values(4,"Bangalore","Jaipur",80000,"10:30:00","01:30:00",8000);
insert into flights values(5,"Bangalore","Ranchi",60000,"10:00:00","12:00:00",7558);
insert into flights values(6,"Ranchi","Bangalore",60000,"10:00:00","12:00:00",6000);
insert into flights values(7,"Mumbai","Delhi",29000,"11:00:00","12:00:00",5467);
insert into flights values(8,"Bangalore","Mumbai",20000,"08:30:00","11:30:00",2000);

insert into aircraft (aid,aname,cruising_range) values (101,"Boeing111",26000),(102,"Boeing112",21500),(103,"Boeing",25000),(104,"Boeing123",23000),(105,"Boeing456",30000);

insert into employees (eid,ename,salary) values (201,"Ajay",50000),(202,"Anika",45000),(203,"Raman",48000),(204,"Samarth",56000);
insert into employees values(205,"Amit",1500);

insert into certified (eid,aid) values (201,101),(201,102),(201,103),(202,104),(202,105),(203,102),(203,103),(203,105),(204,101);

//query 1

select a.aname,a.aid from aircraft a,employees e, certified c where a.aid=c.aid and e.eid=c.eid and e.salary>=50000;

//query 2

select e.eid,e.ename,count(*),max(a.cruising_range) from employees e,certified c,aircraft a where a.aid=c.aid and c.eid=e.eid group by(e.eid) having count(*)>=3;

//query 3

select e.eid,e.ename from employees e where e.salary<(select min(f.price) from flights f );

//query 4

select e.eid,e.ename from employees e where e.salary<(select min(f.price) from flights f where f.fromm="Bangalore" and f.too="Mumbai");

//query 5

select max(e.salary) from employees e where e.salary not in(select max(e.salary) from employees e);

//query 6

create view list as (select e.eid,e.ename,a.aid, a.aname from employees e ,aircraft a,certified c where a.aid=c.aid and e.eid=c.eid);

select * from list;

create database sailors;

use sailors;

create table sailor(sid int primary key, sname varchar(20), rating int, age int);

create table boats(bid int primary key, bname varchar(20), color varchar(10));

create table reserves (sid int,foreign key(sid) references sailor(sid), bid int,foreign key(bid) references boats(bid), day date);

insert into sailor(sid,sname,rating,age) values (1,"Ram", 4,45),(2,"Ajay",3,30),(3,"Mohan",4,35),(4,"Anita",5,39),(5,"Dheeraj",3,32),(6,"Abhay",5,43),(7,"Amit",3,34),(8,"Divya",3,40);

insert into boats(bid, bname, color) values (101,"Peril","Blue"),(102,"Seaking","Red"),(103,"Sharks","Blue"),(104,"Tornado","Green"),(105,"Pearls","White"),(106,"BonVoyage","Red"),(107,"Crew","Green"),(108,"SailMast","White"),(109,"Oceans","White");

insert into reserves(sid,bid,day) values(1,101,"2022-05-03"),(2,101,"2019-04-23"),(2,101,"2018-09-23"),(2,102,"2023-09-23"),(1,109,"2012-09-23"),(3,102,"2012-07-22"),(4,105,"2023-04-30"),(5,106,"2021-11-11"),(6,103,"2012-04-21"),(7,107,"2020-04-21"),(8,108,"2010-04-23");

//query 1

select s.sname,s.age from sailor s,boats b,reserves r where b.bid=r.bid and s.sid=r.sid and b.color="Red" order by s.age;

//query 2

select s.sname from sailor s,boats b,reserves r where b.bid=r.bid and s.sid=r.sid and b.bid=103;

//query 3

 select s.sname,s.age from sailor s where s.age<= all(select age from sailor);

//query 4

select s.rating,avg(s.age) from sailor s group by s.rating;

//query 5
select s.sname,s.rating from sailor s where s.rating>(select s.rating from sailor s where s.sname="Ajay");
//creation and insertion

create database company;

use company;

create table employee (fname varchar(10),lname varchar(10), eid int primary key,bdate date, address varchar(50), gender varchar(10),salary int,super_eid int,dno int);

create table department (dname varchar(20),dno int primary key, d_mgr_id int,foreign key(d_mgr_id) references employee(eid), mgr_start_date date);

create table dept_loc(dno int,foreign key(dno) references department(dno),dloc varchar(20));

create table project (pname varchar(20), pno int primary key, ploc varchar(20),dno int,foreign key(dno) references department (dno));

create table works_on (eid int, foreign key(eid) references employee(eid), pno int, foreign key(pno) references project(pno),hrs int);

create table dependent (eid int,foreign key(eid) references employee(eid),dep_name varchar(20), gender varchar(10), bdate date, relation varchar(10));

//inserting values

insert into employee values("Aman","Kumar",1,"1965-09-08","Mumbai","Male",50000,2,5);
insert into employee(fname,lname,eid,bdate,address,gender,salary,super_eid,dno) values("Jay","Singh",2,"1966-04-23","Pune","Male",68000,8,2),("Preeti","Jain",3,"1977-08-21","Bangalore","Female",45000,4,1),("Anika","Kumari",4,"1987-03-22","Delhi","Female",60000,8,1),("Rishi","Goyal",5,"1969-09-05","Jaipur","Male",40000,2,1),("Shruti","S",6,"1970-05-13","Kolkata","Female",50000,4,3),("Rishab","Jha",7,"1988-03-12","Hyderabad","Male",45000,6,3),("Mayank","Goenka",8,"1978-03-22","Delhi","Male","70000",null,1);

insert into department (dname, dno, d_mgr_id,mgr_start_date) values ("HR",1,8,"2017-09-07"),("Admin",2,2,"2019-03-01"),("Research",3,6,"2020-09-04");

insert into dept_loc(dno, dloc) values (1,"Mumbai"),(2,"Delhi"),(2,"Bangalore"),(3,"Kolkata"),(2,"Hyderabad");

insert into project(pname, pno, ploc, dno) values ("ProductX",1,"Mumbai",1),("ProductY",2,"Bangalore",1),("ProductZ",3,"Delhi",2),("ProductA",4,"Mumbai",2),("ProductB",5,"Hyderabad",2),("ProductC",6,"Kolkata",3),("ProductD",7,"Jaipur",3);

insert into works_on (eid,pno,hrs) values (1,3,20),(1,4,15),(2,3,15),(2,5,25),(2,4,7),(3,1,10),(4,1,10),(8,2,10),(5,2,10),(6,7,10),(6,6,15),(7,6,15),(7,7,10);

insert into dependent(eid,dep_name,gender,bdate,relation) values (1,"Anita","Female","1985-09-30","Spouse"),(1,"Shaurya","Male","2002-12-12","Son"),(2,"Rishika","Female","1988-03-20","Spouse"),(3,"Nikhil","Male","1986-03-29","Spouse"),(3,"Ananya","Female","2002-09-21","Daughter"),(3,"Vineet","Male","2003-02-12","Son"),(4,"Jayant","Male","1988-04-23","Spouse"),(5,"Ruhi","Female","2002-09-21","Daughter"),(5,"Anaya","Female","1999-11-20","Daughter");

//altering table employee to add foreign key constraints

alter table employee add constraint super_eid foreign key(super_eid) references employee(eid);

alter table employee add constraint dno foreign key(dno) references department(dno);

//query1

select e.fname,e.lname,(1.1*e.salary) from employee e,works_on w,project p where p.pname="ProductX" and p.pno=w.pno and w.eid=e.eid;

//query2

select e.fname,e.lname,e.address,e.dno from employee e order by (e.dno);

//query 3

select e.fname,e.lname,e.address,d.dname from employee e,department d where e.dno=d.dno and d.dname="Research";

//query 4

select e.fname,e.lname,p.pno,p.pname,d.dno,d.dname from employee e,project p,works_on w,department d where e.eid=w.eid and w.pno=p.pno and p.dno=d.dno order by d.dno,e.lname,e.fname;

//query 5

create view dept_info as (select d.dno,d.dname,count(*),sum(e.salary) from employee e,department d where d.dno=e.dno group by d.dno);





1. Consider the following restaurant database with the following attributes- Name, address- 
(building, street, area, pincode), id, cuisine, nearby landmarks, online delivery- yes/no, famous for 
(name of the dish)
Solution :
Create 10 documents with data relevant to the following questions. Write and execute 
MongoDB queries:
>use restaurant
>db.createCollection(resto)
>db.resto.insert({"name" : "swiggy", "address" : { "building" : 20, "street" : "30th", "area" : 
"basavanagudi", "pincode" : 560010 }, "id" : 111, "cuisine" : "north", "nearby" : "govt school", 
"online_delivery" : "yes", "famous_for" : "jamoon" })
or
>i=({"name" : "ganesh", "address" : { "building" : 30, "street" : "50th", "area" : "basavanagudi", 
"pincode" : 560010 }, "id" : 222, "cuisine" : "north", "nearby" : "temple", "online_delivery" : "yes", 
"famous_for" : "halwa" }
>db.resto.save(i)
insert like above 10 values
i. List the name and address of all restaurants in Bangalore with Italian cuisine.
> db.resto.find({"address.area":"basavanagudi","cuisine":"north"},{name:1,address:1})
ii. List the name, address and nearby landmarks of all restaurants in Bangalore where
north Indian thali is available.
>db.resto.find({"address.area":"basavanagudi","cuisine":"north","famous_for":"indian 
thali"},{name:1,address:1,nearby:1})
2. Consider the following restaurant table with the following attributes- Name, address- (building, 
street, area, pincode), id, cuisine, nearby landmarks, online delivery- yes/no, famous for (name of 
the dish)
Solution :
Create 10 documents with data relevant to the following questions. Write and execute 
MongoDB queries:
>use restaurant
>db.createCollection(resto)
>db.resto.insert({"name" : "swiggy", "address" : { "building" : 20, "street" : "30th", "area" : 
"basavanagudi", "pincode" : 560010 }, "id" : 111, "cuisine" : "north", "nearby" : "govt school", 
"online_delivery" : "yes", "famous_for" : "jamoon" })
or
>i=({"name" : "ganesh", "address" : { "building" : 30, "street" : "50th", "area" : "basavanagudi", 
"pincode" : 560010 }, "id" : 222, "cuisine" : "north", "nearby" : "temple", "online_delivery" : "yes", 
"famous_for" : "halwa" }
>db.resto.save(i)
insert like above 10 values
i. List the details of all restaurant except nearby details that are present in Bangalore 
where Indian thali is available.
> db.resto.find({"address.area":"basavanagudi","cuisine":"north","famous_for":"indian 
thali"},{nearby:0})
ii. List the name and address of restaurants and also the dish the restaurant is famous 
in Bangalore.
>db.resto.find({"address.area":"basavanagudi"},{name:1,address:1,famous_for:1})
3. Consider the following Tourist places table with the following attributes- place, address- (state), 
id, tourist attractions, best time of the year to visit, modes of transport (include nearest airport, 
railway station etc), accommodation, food- what not to miss for sure
Solution:
Create 10 collections with data relevant to the following questions. Write and execute 
MongoDB queries:
>use tourist
>db.createCollection(touristplaces)
>db.touristplaces.insert({"place" : "Bangalore", "address" : { "state" : “karnataka”}, "id" : “blr”, 
"tourist_attraction" : "vidhana soudha", "best_time_to_visit" : "winter", "nearby_transport_mode" :
{“airport”: “KIA”, “bus_stand”: “majestic”, “metrostn”: “vidhanasoudha”}, “accomodation”: 
“hotels”, “food_not_to_miss”: “DOSA”})
or
>i=({"place" : "madhurai", "address" : { "state" : “temilnadu”}, "id" : “mdri”, "tourist_attraction" : 
"temples", "best_time_to_visit" : "monsoon", "nearby_transport_mode" :{“airport”: “chennai”, 
“bus_stand”: “madurai”}, “accomodation”: “hotels”, “food_not_to_miss”: [ “IDLI”, “PONGAL”]})
>db.resto.save(i)
insert like above 10 values
i. List all the tourist places of Karnataka
> db.resto.find({"address.state":"karnataka"},{places:1})
ii. List the places sorted state wise
> db.resto.find().sort({address.state:1})
4. Consider the following Movie table with the following attributes- Actor_name, Actor_id, 
Actor_birthdate, Director_name, Director_id, Director_birthdate, film_title, year of production, type
(thriller, comedy etc).
Solution :
Create 10 collections with data relevant to the following questions. Write and execute 
MongoDB queries:
>use moviedb
>db.createCollection(movies)
>db.movies.insert({"Actor_name" : "john", "Actor_id" : 123, "Actor_birthdate" : 20/12/1990, 
"Director_name" :“krish”, “Director_id”:111,“Director_birthdate”: 02/02/1980, “film_title”: “dia”, 
“year_of_production”:2018, “type”: “comedy”})
or
>i=({"Actor_name" : "krishna", "Actor_id" : 456, "Actor_birthdate" : 20/08/1989, "Director_name"
:“ram”, “Director_id”:222,“Director_birthdate”: 12/02/1986, “film_title”: “avengers”, 
“year_of_production”:2020, “type”: “thriller”})
>db.movies.save(i)
insert like above 10 values
i. List all the movies acted by John in the year 2018
> db.movies.find({"Actor_name" : "john",“year_of_production”:2018})
ii. List only the actors name and type of the movie directed by Ram.
> db.movies.find({"Director_name" :“ram”},{Actor_name:1,type:1})
5. Consider the following Movie table with the following attributes- Actor_name, Actor_id, 
Actor_birthdate, Director_name, Director_id, Director_birthdate, year of production, type (thriller, 
comedy etc).
Solution :
Create 10 collections with data relevant to the following questions. Write and execute 
MongoDB queries:
>use moviedb
>db.createCollection(movies)
>db.movies.insert({"Actor_name" : "john", "Actor_id" : 123, "Actor_birthdate" : 20/12/1990, 
"Director_name" :“krish”, “Director_id”:111,“Director_birthdate”: 02/02/1980, “film_title”: “dia”, 
“year_of_production”:2018, “type”: “comedy”})
or
>i=({"Actor_name" : "krishna", "Actor_id" : 456, "Actor_birthdate" : 20/08/1989, "Director_name"
:“ram”, “Director_id”:222,“Director_birthdate”: 12/02/1986, “film_title”: “avengers”, 
“year_of_production”:2020, “type”: “thriller”})
>db.movies.save(i)
insert like above 10 values
i. List all the movies acted by John or Elly in the year 2012
> db.movies.find({$or:[{"Actor_name" : "john","Actor_name" : "elly"}], 
“year_of_production”:2012})
ii. List only the name and type of the movie where Ram has acted, sorted by movie 
names.
> db.movies.find({"Actor_name" :“ram”},{film_title:1,type:1}).sort({film_title:1}
