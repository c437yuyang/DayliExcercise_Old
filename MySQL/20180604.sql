create table if not exists actor
(
    actor_id smallint(5) primary key not null,
    first_name varchar(45) not null,
    last_name varchar(45) not null,
    last_update timestamp not null default now()
);

insert into actor 
values(1,'PENELOPE','GUINESS','2006-02-15 12:34:33'),
    (2,'NICK','WAHLBERG','2006-02-15 12:34:33')

insert into actor
values(3,'ED','CHASE','2006-02-15 12:34:33');

alter table actor add unique key uniq_idx_firstname(first_name);
create index idx_lastname on actor(last_name);

# 针对actor表创建视图actor_name_view，只包含first_name以及last_name两列，并对这两列重新命名，first_name为first_name_v，last_name修改为last_name_v：
create view actor_name_view as
    select first_name as first_name_v,last_name as last_name_v
        from actor

