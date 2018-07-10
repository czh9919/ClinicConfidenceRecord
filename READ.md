# Clinic Confidence Record(诊所信息管理系统)

## 描述

完成小型诊所的简单信息管理

## 功能

添加记录，在一条记录中，有医生的*专业，诊费，姓名，id*，患者的*药费，诊费，姓名，id*。

## 实现

定义一个class名为**CUnitClinicConfidenceRecord**，利用STL中的vector实现可变数组，名为CClinicConfidenceRecord。利用set保证医生和患者不重复

    set<Chuman> Sethuman;
    set<Cdoctor> SetDoctor;
    vector<CUnitClinicConfidenceRecord> CClinicConfidenceRecord;

## 命名规范

对**自定义类的取名**的第一个字母为“**C**”，且构成类名的每个单词第一个字母大写，如*CUnitClinicConfidenceRecord*。  
对**实例化**后的类名的第一个字母为“**c**”，构成其名的每个单词的第一个字母大写，对变量取名时，第一个字母为该变量的类型的第一个字母的小写，所有单词第一个字母大写，如*iTempId*。  
对私有类型加双下划线,如__iId。  
