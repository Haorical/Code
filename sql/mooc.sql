CREATE DATABASE `homework_mooc` CHARACTER SET 'utf8' COLLATE 'utf8_general_ci' -- 数据库

CREATE TABLE `homework_mooc`.`book`  (
  `id` int NOT NULL,
  `title` varchar(255) NULL,
  `publisherid` int NULL,
  PRIMARY KEY (`id`)
); -- book
 
CREATE TABLE `homework_mooc`.`book_author`  (
  `bookid` int NOT NULL,
  `author` varchar(255) NOT NULL,
  PRIMARY KEY (`bookid`, `author`)
); -- book_author

CREATE TABLE `homework_mooc`.`publish`  (
  `publisherid` int NOT NULL,
  `name` varchar(255) NULL,
  `address` varchar(255) NULL,
  `phone` varchar(255) NULL,
  PRIMARY KEY (`publisherid`)
); -- publish

CREATE TABLE `homework_mooc`.`borrow`  (
  `bookid` int NOT NULL,
  `cardid` int NOT NULL,
  `dateout` datetime NULL,
  `dueout` datetime NULL,
  `is_return` int NULL,
  PRIMARY KEY (`bookid`, `cardid`)
); -- borrow

CREATE TABLE `homework_mooc`.`card`  (
  `cardid` int NOT NULL,
  `name` varchar(255) NULL,
  `address` varchar(255) NULL,
  `phone` varchar(255) NULL,
  PRIMARY KEY (`cardid`)
); -- card

-- ⑴ 查询借阅过“机械工业出版社”出版的所有书籍的借书人姓名和电话。
select name,phone
from card
where not exists
(
    select *
    from publish,book
    where book.publisherid=publish.publisherid and publish.name='机械工业出版社' and not exists
    (
        select *
        from borrow
        where borrow.cardid=card.cardid and borrow.bookid=book.id
    )
);
-- ⑵ 建立视图，显示2021年期间没有被借过的书籍名称和出版社名称。
create view a
as
select book.title,publish.name
from book,publish,borrow
where book.publisherid=publish.publisherid and borrow.bookid=book.id and book.id not in
(
    select bookid
    from borrow
    where borrow.dateout=2021
);
-- ⑶ 建立超期未还书籍的视图，显示书籍编号和名称、以及借书人姓名和电话。
create view b
as
select book.id,book.title,card.name,card.phone
from book,card,borrow
where book.id=borrow.bookid and card.id=borrow.cardid and borrow.is_return=0 and borrow.dueout<NOW();
-- ⑷ 建立热门书籍的视图，显示2021年期间借出次数最多的10本书籍名称。
create view c
as
select book.title
from book,borrow
where book.id=borrow.bookid
group by borrow.bookid
order by count(*) desc
limit 0,10;
-- ⑸ 删除2015年期间《计算机基础教程》书籍的借还信息。
delete
from borrow
where borrow.bookid in(
    select id
    from book
    where title='计算机基础教程'
);
