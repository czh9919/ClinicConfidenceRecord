#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Chuman
{
public:
  Chuman() = default;
  Chuman(string sName,int iId):__sName(sName),__iId(iId){}
  int returnId ()const;
  int ChangeId(int iId);
  string returnName();
  string ChangeName(string sName);
  friend int operator<(Chuman chumaFirst, Chuman chumanSecound);
  bool operator==(Chuman chumansecound)
  {
      return ((*this).returnId() == chumansecound.returnId());
  }
  Chuman operator=(Chuman chumansecound)
  {
      __iId = chumansecound.__iId;
      __sName= chumansecound.__sName;
      return (*this);
  }
  ~Chuman() = default;
  
private:
  string __sName;
  int __iId;
};
int operator<(Chuman chumaFirst,Chuman chumansecound)
{
    if(chumaFirst.returnId() < chumansecound.returnId())
        return 1;
    return 0;
}
string Chuman::returnName()
{
    return __sName;
}
string Chuman::ChangeName(string sName)
{
    __sName = sName;
    return sName;
}
int Chuman:: returnId() const
{
    return __iId;
}
int Chuman::ChangeId(int iId)
{
    __iId = iId;
    return iId;
}
class Cdoctor:public Chuman
{
public:
  
  Cdoctor(string sName,int iId,int iSpecialty) : Chuman(sName, iId),__iSpecialty(iSpecialty){}
  ~Cdoctor() = default;
  friend bool operator<(Cdoctor CdoctorFirst,Cdoctor cDoctorSecound);
  bool operator==(Cdoctor cDoctorSecound)
  {
      return (*this).returnId() == cDoctorSecound.returnId();
  }
  Cdoctor operator=(Cdoctor ctemp)
  {
      ChangeId(ctemp.returnId());
      ChangeName(ctemp.returnName());
      __iSpecialty = ctemp.__iSpecialty;
      return (*this);
  }
private:
  int __iSpecialty;
};
bool operator<(Cdoctor CdoctorFirst,Cdoctor cDoctorSecound)
{
    return CdoctorFirst.returnId() < cDoctorSecound.returnId();
}
class CUnitClinicConfidenceRecord
{
private:
  Chuman __cpatient;
  Cdoctor __cdoctor;
  int __iDrugFee;
  int __iOfficeVistFee;
  int __iRecordId;

public:
  CUnitClinicConfidenceRecord() = default;
  CUnitClinicConfidenceRecord(Cdoctor cdoctor,Chuman cpatient,int iDrugFee, int iOfficeVistFee,int iRecordId) :__cpatient(cpatient),__cdoctor(cdoctor) ,__iDrugFee(iDrugFee), __iOfficeVistFee(iOfficeVistFee),__iRecordId(iRecordId) {}
  Chuman ReturnCPatient()
  {
      return __cpatient;
  }
  Cdoctor ReturnCdoctor()
  {
      return __cdoctor;
  }
  int ReturnDrugFee()
  {
      return __iDrugFee;
  }
  int ReturnOfficeVistFee()
  {
      return __iOfficeVistFee;
  }
  int ReturnRecordId()
  {
      return __iRecordId;
  }
  ~CUnitClinicConfidenceRecord() = default;
};
set<Chuman> Sethuman;
set<Cdoctor> SetDoctor;
vector<CUnitClinicConfidenceRecord> CClinicConfidenceRecord;
void menu()
{
    cout << "1.Add doctors" << endl;
    cout << "2.Add a unit of record" << endl;
    cout << "3.View patient records" << endl;
    cout << "4.View billing records" << endl;
    cout << "5.Display information about the patient and the attending physician" << endl;
    cout << "6.Count all patient costs" << endl;
    cout << "7.View the Doctors' Records" << endl;
    
    //cout << "8.Save to file" << endl;
    //cout << "9.Read from file" << endl;
    cout << "Enter your option" << endl;
}
Cdoctor AddADoctor()
{
    int iTempId;
    string sTempName;
    int iTempSpecialty;
    cout << "Enter the doctor's specialty" << endl;
    cout << "1.surgeon 2.prediatrician 3.obstetrician 4.general practitioner" << endl;
    cin >> iTempSpecialty;
    cout << "Enter the doctor's name" << endl;
    cin >> sTempName;
    cout << "Enter the doctor's id" << endl;
    cin >> iTempId;
    Cdoctor ctempdoctor( sTempName, iTempId,iTempSpecialty);
    return ctempdoctor;
}
void AddDoctor()
{
    while (1)
    {
        Cdoctor ctempdoctor = AddADoctor();
        SetDoctor.insert(ctempdoctor);
        cout << "would you like to enter another doctor's information" << endl;
        cout << "Enter 1 to continue to enter the doctor's information" << endl;
        int itemp;
        cin >> itemp;
        if(itemp!=1)
        {
            break;
        }
    }
}
Cdoctor FindDoctor()
{
    cout << "enter the doctor's id" << endl;
    int iTempId;
    cin >> iTempId;
    for (auto it = SetDoctor.begin(); it !=SetDoctor.end(); it++)
    {
        
        if (iTempId==(*it).returnId()) 
        {
            return (*it);
        }
    }
    cout << "Not found ,enter another doctor's information" << endl;
    Cdoctor ctempdoctor = AddADoctor();
    SetDoctor.insert(ctempdoctor);
    return ctempdoctor;
}
Chuman AddAhuman()
{
    int iTempId;
    string sTempName;
    cout << "Enter the human's name" << endl;
    cin >> sTempName;
    cout << "Enter the human's id" << endl;
    cin >> iTempId;
    Chuman chuman(sTempName, iTempId);
    Sethuman.insert(chuman);
    return chuman;
}
Chuman FindHuman()
{
    cout << "enter the human's id" << endl;
    int iTempId;
    cin >> iTempId;
    for (auto it = Sethuman.begin(); it !=Sethuman.end(); it++)
    {
        
        if (iTempId==(*it).returnId()) 
        {
            return (*it);
        }
    }
    cout << "Not found ,enter another human's information" << endl;
    Chuman ctemphuman = AddAhuman();
    Sethuman.insert(ctemphuman);
    return ctemphuman;
}
void AddUnitRecord()
{
    int iOfficeVistFee;
    int iDrugFee;
    int iRecordId;
    Cdoctor cdoctor = FindDoctor();
    Chuman chuman=FindHuman();
    cout << "Enter a Office Vist Fee" << endl;
    cin >> iOfficeVistFee;
    cout << "Enter drug fee" << endl;
    cin >> iDrugFee;
    cout << "Enter record Id" << endl;
    cin >> iRecordId;
    CUnitClinicConfidenceRecord cUnitClinicConfidenceRecord(cdoctor, chuman, iDrugFee, iOfficeVistFee,iRecordId);
    CClinicConfidenceRecord.push_back(cUnitClinicConfidenceRecord);
}
void ViewPatientRecords()
{
    cout << "enter the patient's id" << endl;
    int iTempId;
    cin >> iTempId;
    int iSumDrugFee = 0;
    int iSumOfficeVistFee = 0;
    for (auto i = CClinicConfidenceRecord.begin(); i !=CClinicConfidenceRecord.end(); i++)
    {
        
        if ((*i).ReturnCPatient().returnId()==iTempId) {
            cout << "Name:" << (*i).ReturnCPatient().returnName()<< endl;
            cout << "Drug Fee is " << (*i).ReturnDrugFee()<< endl;
            iSumDrugFee += (*i).ReturnDrugFee();
            cout << "Office Vist Fee is" << (*i).ReturnOfficeVistFee() << endl;
            iSumOfficeVistFee = (*i).ReturnOfficeVistFee();
        }
        
    }
    cout << "Sum of Drug Fee is " << iSumDrugFee << endl;
    cout << "Sum of Office Vist Fee is " << iSumOfficeVistFee << endl;
}
void ViewBillingRecords()
{
    cout << "enter the record's id" << endl;
    int iTempId;
    cin >> iTempId;
    for (auto i = CClinicConfidenceRecord.begin(); i !=CClinicConfidenceRecord.end(); i++)
    {
        
        if ((*i).ReturnRecordId()==iTempId) {
            cout << "Name:" << (*i).ReturnCPatient().returnName()<< endl;
            cout << "Patient's id:" << (*i).ReturnCPatient().returnId() << endl;
            cout << "Drug Fee is " << (*i).ReturnDrugFee()<< endl;
            cout << "Office Vist Fee is" << (*i).ReturnOfficeVistFee() << endl;
            break;
        }
        
    }
}
void ViewDoctorRecords()
{
    cout << "enter the Doctor's id" << endl;
    int iTempId;
    cin >> iTempId;
    for (auto i = CClinicConfidenceRecord.begin(); i !=CClinicConfidenceRecord.end(); i++)
    {
        
        if (((*i).ReturnCdoctor()).returnId()==iTempId) {
            cout << "Patient's Name:" << (*i).ReturnCPatient().returnName()<< endl;
            cout << "Patient's id:" << (*i).ReturnCPatient().returnId() << endl;
            cout << "Drug Fee is " << (*i).ReturnDrugFee()<< endl;
            cout << "Office Vist Fee is" << (*i).ReturnOfficeVistFee() << endl;
            break;
        }
    }
}
void DisplayInformationAboutPatientAndPhysician()
{
    cout << "enter the patient's id" << endl;
    int iTempId;
    cin >> iTempId;
    int iSumDrugFee = 0;
    int iSumOfficeVistFee = 0;
    for (auto i = CClinicConfidenceRecord.begin(); i !=CClinicConfidenceRecord.end(); i++)
    {
        
        if ((*i).ReturnCPatient().returnId()==iTempId) {

            cout << "Doctor's Name:" << (*i).ReturnCdoctor().returnName()<< endl;
            cout << "Doctor's Id:" << (*i).ReturnCdoctor().returnId()<< endl;
            cout << "Drug Fee is " << (*i).ReturnDrugFee()<< endl;
            cout << "Office Vist Fee is" << (*i).ReturnOfficeVistFee() << endl;
            iSumDrugFee += (*i).ReturnDrugFee();
            iSumOfficeVistFee = (*i).ReturnOfficeVistFee();
        }
        
    }
    cout << "Sum of Drug Fee is " << iSumDrugFee << endl;
    cout << "Sum of Office Vist Fee is " << iSumOfficeVistFee << endl;
}
void CountAllPatientCosts()
{
    cout << "enter the patient's id" << endl;
    int iTempId;
    cin >> iTempId;
    int iSumDrugFee = 0;
    int iSumOfficeVistFee = 0;
    for (auto i = CClinicConfidenceRecord.begin(); i !=CClinicConfidenceRecord.end(); i++)
    {
            iSumDrugFee += (*i).ReturnDrugFee();
            iSumOfficeVistFee = (*i).ReturnOfficeVistFee();
    }
    cout << "Sum of Drug Fee is " << iSumDrugFee << endl;
    cout << "Sum of Office Vist Fee is " << iSumOfficeVistFee << endl;
    cout << "Sum of Drug Fee and Office Vist Fee is" << iSumDrugFee + iSumOfficeVistFee << endl;
}
int main(int argc, char const *argv[])
{
    int iOption;
    menu();
    while (cin>>iOption)
    {
        
        switch (iOption)
        {
            case 1:
                AddDoctor();
                break;
            case 2:
                AddUnitRecord();
                break;
            case 3:
                ViewPatientRecords();
                break;
            case 4:
                ViewBillingRecords();
                break;
            case 5:
                DisplayInformationAboutPatientAndPhysician();
                break;
            case 6:
                CountAllPatientCosts();
                break;
            case 7:
                ViewDoctorRecords();
                break;
            default:
                exit(0);
                break;
        }
        menu();
    }
    return 0;
}
