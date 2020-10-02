// 47. Patient and Doctor Scheduler - create a patient class and a doctor class. Have a
// doctor that can handle multiple patientsand setup a scheduling program where a
// doctor can only handle 16 patients during an 8 hr work day. (4.5)

#include<iostream>
#include<string>
#include<vector>
#include<map>


using namespace std;

//Obs³uga klasy Lekarz
class Doctor
{
private:
	string m_name;
	string m_surname;
	string m_PESEL_number;
	string m_PWZ_number;
	string m_specialisation;

public:
	Doctor(string name, string surname, string PESEL_number, string PWZ_number, string specialisation) : m_name{ name }, m_surname{ surname }, m_PESEL_number{ PESEL_number }, m_PWZ_number{ PWZ_number }, m_specialisation{ specialisation }{}

	string string_to();
	string get_name();
	string get_surname();
	string get_PESEL_number();
	string get_PWZ_number();
	string get_specialisation();
	void set_name(string name);
	void set_surname(string surname);
	void set_PESEL_number(string PESEL_number);
	void set_PWZ_number(string PWZ_number);
	void set_specialisation(string specialisation);
};


class Appointment : public Doctor
{
private:
	string m_hour;
	string m_minutes;
	string m_day;
	string m_month;
	string m_year;
public:
	Appointment(string name, string surname, string PESEL_number, string PWZ_number, string specialisation, string hour, string minutes, string day, string month, string year) : Doctor(name, surname, PESEL_number, PWZ_number, specialisation), m_hour{ hour }, m_minutes{ minutes }, m_day{ day }, m_month{ month }, m_year{ year }{}

	string string_to();
	string get_hour();
	string get_minutes();
	string get_day();
	string get_month();
	string get_year();
	void set_hour(string hour);
	void set_minutes(string minutes);
	void set_day(string day);
	void set_month(string month);
	void set_year(string year);
	using Doctor::get_PWZ_number;

	bool operator<(const Appointment& other) const
	{
		return std::tie(m_hour, m_minutes, m_day, m_month, m_year) < std::tie(other.m_hour, other.m_minutes, other.m_day, other.m_month, other.m_year);
	}

};

string Doctor::string_to()
{
	return "imie: " + m_name + "\nnazwisko: " + m_surname + "\nnumer PESEL: " + m_PESEL_number + "\nnumer PWZ: " + m_PWZ_number;
}

string Appointment::string_to()
{
	return  "Wizyta: " + m_hour + ":" + m_minutes + " " + m_day + "-" + m_month + "-" + m_year + "\nimie: " + get_name() + "\nnazwisko: " + get_surname() + "\nnumer PESEL: " + get_PESEL_number() + "\nnumer PWZ: " + get_PWZ_number();
}

string Doctor::get_name()
{
	return m_name;
}

string Doctor::get_surname()
{
	return m_surname;
}

string Doctor::get_PESEL_number()
{
	return m_PESEL_number;
}

string Doctor::get_PWZ_number()
{
	return m_PWZ_number;
}

string Doctor::get_specialisation()
{
	return m_specialisation;
}

string Appointment::get_hour()
{
	return m_hour;
}

string Appointment::get_minutes()
{
	return m_minutes;
}

string Appointment::get_day()
{
	return m_day;
}

string Appointment::get_month()
{
	return m_month;
}

string Appointment::get_year()
{
	return m_year;
}

ostream& operator<< (ostream& out, Appointment& rhs)
{
	out << rhs.get_name() << endl << rhs.get_surname() << endl << rhs.get_PESEL_number() << endl << rhs.get_PWZ_number() << endl << rhs.get_hour() << endl << rhs.get_minutes() << endl << rhs.get_day() << endl << rhs.get_month() << endl << rhs.get_year() << endl;
	return out;
}

void Doctor::set_name(string name)
{
	m_name = name;
}

void Doctor::set_surname(string surname)
{
	m_surname = surname;
}

void Doctor::set_PESEL_number(string PESEL_number)
{
	m_PESEL_number = PESEL_number;
}

void Doctor::set_PWZ_number(string PWZ_number)
{
	m_PWZ_number = PWZ_number;
}

void Doctor::set_specialisation(string specialisation)
{
	m_specialisation = specialisation;
}

void Appointment::set_hour(string hour)
{
	m_hour = hour;
}

void Appointment::set_minutes(string minutes)
{
	m_minutes = minutes;
}

void Appointment::set_day(string day)
{
	m_day = day;
}

void Appointment::set_month(string month)
{
	m_month = month;
}

void Appointment::set_year(string year)
{
	m_year = year;
}

//Obs³uga klasy Pacjent
class Patient
{
private:
	string m_name;
	string m_surname;
	string m_adres;
	string m_PESEL_number;

public:
	Patient(string name, string surname, string adres, string PESEL_number) : m_name{ name }, m_surname{ surname }, m_adres{ adres }, m_PESEL_number{ PESEL_number }{}

	string string_to();
	string get_name();
	string get_surname();
	string get_adres();
	string get_PESEL_number();
	void set_name(string name);
	void set_surname(string surnamen);
	void set_adres(string adres);
	void set_PESEL_number(string PESEL_number);
};

string Patient::string_to()
{
	return "imie: " + m_name + "\nnazwisko: " + m_surname + "\nnumer PESEL: " + m_PESEL_number + "\nadres: " + m_adres;
}

string Patient::get_name()
{
	return m_name;
}

string Patient::get_surname()
{
	return m_surname;
}

string Patient::get_adres()
{
	return m_adres;
}

string Patient::get_PESEL_number()
{
	return m_PESEL_number;
}

void Patient::set_name(string name)
{
	m_name = name;
}

void Patient::set_surname(string surname)
{
	m_surname = surname;
}

void Patient::set_adres(string adres)
{
	m_adres = adres;
}

void Patient::set_PESEL_number(string PESEL_number)
{
	m_PESEL_number = PESEL_number;
}

bool SearchMapByValue(map<Appointment, Patient> Patient_Appointment, string function_PESEL_number)
{
	bool SearchResult = false;
	auto it = Patient_Appointment.begin();
	while (it != Patient_Appointment.end())
	{
		if (it->second.get_PESEL_number() == function_PESEL_number)
		{
			SearchResult = true;
		}
		it++;
	}
	return SearchResult;
}

Appointment SearchMapByValue1(map<Appointment, Patient> Patient_Appointment, string function_PESEL_number)
{
	auto it = Patient_Appointment.begin();
	while (it != Patient_Appointment.end())
	{
		if (it->second.get_PESEL_number() == function_PESEL_number)
		{
			return it->first;
		}
		it++;
	}
}

int Assert_16_Visits(map<Appointment, Patient> Patient_Appointment, string assert_PWZ, string assert_day, string assert_month, string assert_year)
{
	int licznik = 0;
	for (pair<Appointment, Patient> element : Patient_Appointment) {
		Appointment Appointment_data = element.first;
		Patient Patients_data = element.second;
		if (Appointment_data.get_PWZ_number() == assert_PWZ && Appointment_data.get_day() == assert_day && Appointment_data.get_month() == assert_month && Appointment_data.get_year() == assert_year)
		{
			licznik += 1;
		}
	}

	return licznik;
}

//Umawianie wizyt
void Main_panel()
{
	cout << "Main panel\n1. Patients data and appointments\n2. Doctors data\n3. Doctors calendar\n4. Add appointment\n5. Add Patient\n6. Add Doctor\n\nPress 1-6 to choose an action or any other number to leave: ";
}

void case_1(vector<Patient> Patient_vector, map<Appointment, Patient> Patient_Appointment, vector<Appointment> Appointment_vector)
{
	for (int i = 0; i < Patient_vector.size(); i++)
	{
		cout << Patient_vector[i].string_to() << endl << endl;

		if (SearchMapByValue(Patient_Appointment,Patient_vector[i].get_PESEL_number()) == true)
		{
			cout << SearchMapByValue1(Patient_Appointment, Patient_vector[i].get_PESEL_number()).string_to() << endl << endl << endl;
		}
		
	}
}

void case_2(vector<Doctor> Doctor_vector)
{
	for (int i = 0; i < Doctor_vector.size(); i++)
	{
		cout << Doctor_vector[i].string_to() << endl << endl;
	}
}

void case_3(map<Appointment, Patient> Patient_Appointment)
{
	for (pair<Appointment, Patient> element : Patient_Appointment) {
		Appointment Appointment_data = element.first;
		Patient Patients_data = element.second;
		cout << Appointment_data.string_to() << endl << "Dane pacjenta:\n" << Patients_data.string_to() << endl << endl;
	}

}

Appointment case_4(map<Appointment, Patient> Patient_Appointment)
{
	string name_of_doc, surname_of_doc, PESEL_number_of_doc, PWZ_number, specialisation, hour, minutes, day, month, year;
	Appointment Appointment_case4("0", "0", "0", "0", "0","0","0","0","0","0");
	cout << "Lekarz: " << endl << "Podaj imie: ";
	cin >> name_of_doc;
	Appointment_case4.set_name(name_of_doc);
	cout << "\nPodaj nazwisko: ";
	cin >> surname_of_doc;
	Appointment_case4.set_surname(surname_of_doc);
	cout << "\nPodaj numer PESEL: ";
	Appointment_case4.set_PESEL_number(PESEL_number_of_doc);
	cin >> PESEL_number_of_doc;
	cout << "\nPodaj numer PWZ: ";
	cin >> PWZ_number;
	Appointment_case4.set_PWZ_number(PWZ_number);
	cout << "\nPodaj specjalizacje: ";
	cin >> specialisation;
	Appointment_case4.set_specialisation(specialisation);
	cout << "\nPodaj godzine: ";
	cin >> hour;
	Appointment_case4.set_hour(hour);
	cout << "\nPodaj minuty: ";
	cin >> minutes;
	Appointment_case4.set_minutes(minutes);
	cout << "\nPodaj dzien : ";
	cin >> day;
	Appointment_case4.set_day(day);
	cout << "\nPodaj miesiac: ";
	cin >> month;
	Appointment_case4.set_month(month);
	cout << "\nPodaj rok: ";
	cin >> year;
	Appointment_case4.set_year(year);

	if (Assert_16_Visits(Patient_Appointment, PWZ_number, day, month, year) == 16)
	{
		Appointment_case4.set_PWZ_number("0");
	}

	return Appointment_case4;
}

Patient case_5(void)
{
	string name, surname, adres, PESEL_number;
	Patient Patient_case_5("0","0","0","0");

	cout << "Dodawanie pacjenta: " << endl << "Podaj imie: ";
	cin >> name;
	Patient_case_5.set_name(name);

	cout << "\nPodaj nazwisko: ";
	cin >> surname;
	Patient_case_5.set_surname(surname);

	cout << "\nPodaj adres: ";
	cin >> adres;
	Patient_case_5.set_adres(adres);

	cout << "\nPodaj numer PESEL: ";
	cin >> PESEL_number;
	Patient_case_5.set_PESEL_number(PESEL_number);

	return Patient_case_5;
}

Doctor case_6(void)
{
	string name, surname, PESEL_number, PWZ_number, specialisation;
	Doctor Doctor_case_6("0","0","0","0","0");

	cout << "Dodawanie lekarza: " << endl << "Podaj imie: ";
	cin >> name;
	Doctor_case_6.set_name(name);

	cout << "\nPodaj nazwisko: ";
	cin >> surname;
	Doctor_case_6.set_surname(surname);

	cout << "\nPodaj numer PESEL: ";
	cin >> PESEL_number;
	Doctor_case_6.set_PESEL_number(PESEL_number);

	cout << "\nPodaj numer PWZ: ";
	cin >> PWZ_number;
	Doctor_case_6.set_PWZ_number(PWZ_number);

	cout << "\nPodaj specjalizacje: ";
	cin >> specialisation;
	Doctor_case_6.set_specialisation(specialisation);

	return Doctor_case_6;
}

int main()
{
	map<Appointment, Patient> Patient_Appointment;

	vector<Doctor> Doctor_vector;
	Doctor Doctor1("Jan", "Kowalski", "78101599910", "32546563", "Laryngolog");
	Doctor Doctor2("Andrzej", "Nowak", "90061012345", "7654321", "Nefrolog, Internista");
	Doctor Doctor3("a", "a", "a", "a", "a");
	Doctor_vector.push_back(Doctor1);
	Doctor_vector.push_back(Doctor2);
	Doctor_vector.push_back(Doctor3);

	vector<Patient> Patient_vector;
	Patient Patient1("Ryszard", "Malinowski", "ul. Marsza³kowska 13/16 12-034 Warszawa", "67010712345");
	Patient Patient2("Jarema", "Wisniowiecki", "ul. 3-go Maja 12/17 99-097 Krakow", "87032212345");
	Patient Patient3("Jan", "Zamoyski", "ul. Pilsudskiego 131/76 99-097 Zamosc", "11235712192");
	Patient Patient4("Onufry", "Zagloba", "ul. Sobieskiego 78/65 12-098 Lublin", "1234567");
	Patient Patient5("b", "b", "b", "b");
	Patient_vector.push_back(Patient1);
	Patient_vector.push_back(Patient2);
	Patient_vector.push_back(Patient3);
	Patient_vector.push_back(Patient4);
	Patient_vector.push_back(Patient5);

	vector<Appointment> Appointment_vector;
	Appointment Appointment1("Jan", "Kowalski", "78101599910", "1234567", "Laryngolog", "11", "30", "30", "01", "2020");
	Appointment Appointment2("Jan", "Kowalski", "78101599910", "1234567", "Laryngolog", "12", "00", "30", "01", "2020");
	Appointment Appointment3("Jan", "Kowalski", "78101599910", "1234567", "Laryngolog", "12", "30", "30", "01", "2020");
	Appointment Appointment4("Andrzej", "Nowak", "90061012345", "7654321", "Nefrolog, Internista", "12", "30", "01", "02", "2020");
	Appointment Appointment_example_1("a", "a", "a", "a", "a", "08", "00", "10", "10", "2020");
	Appointment Appointment_example_2("a", "a", "a", "a", "a", "08", "30", "10", "10", "2020");
	Appointment Appointment_example_3("a", "a", "a", "a", "a", "09", "00", "10", "10", "2020");
	Appointment Appointment_example_4("a", "a", "a", "a", "a", "09", "30", "10", "10", "2020");
	Appointment Appointment_example_5("a", "a", "a", "a", "a", "10", "00", "10", "10", "2020");
	Appointment Appointment_example_6("a", "a", "a", "a", "a", "10", "30", "10", "10", "2020");
	Appointment Appointment_example_7("a", "a", "a", "a", "a", "11", "00", "10", "10", "2020");
	Appointment Appointment_example_8("a", "a", "a", "a", "a", "11", "30", "10", "10", "2020");
	Appointment Appointment_example_9("a", "a", "a", "a", "a", "12", "00", "10", "10", "2020");
	Appointment Appointment_example_10("a", "a", "a", "a", "a", "12", "30", "10", "10", "2020");
	Appointment Appointment_example_11("a", "a", "a", "a", "a", "13", "00", "10", "10", "2020");
	Appointment Appointment_example_12("a", "a", "a", "a", "a", "13", "30", "10", "10", "2020");
	Appointment Appointment_example_13("a", "a", "a", "a", "a", "14", "00", "10", "10", "2020");
	Appointment Appointment_example_14("a", "a", "a", "a", "a", "14", "30", "10", "10", "2020");
	Appointment Appointment_example_15("a", "a", "a", "a", "a", "15", "00", "10", "10", "2020");
	Appointment Appointment_example_16("a", "a", "a", "a", "a", "15", "30", "10", "10", "2020");

	Appointment_vector.push_back(Appointment1);
	Appointment_vector.push_back(Appointment2);
	Appointment_vector.push_back(Appointment3);
	Appointment_vector.push_back(Appointment4);
	Appointment_vector.push_back(Appointment_example_1);
	Appointment_vector.push_back(Appointment_example_2);
	Appointment_vector.push_back(Appointment_example_3);
	Appointment_vector.push_back(Appointment_example_4);
	Appointment_vector.push_back(Appointment_example_5);
	Appointment_vector.push_back(Appointment_example_6);
	Appointment_vector.push_back(Appointment_example_7);
	Appointment_vector.push_back(Appointment_example_8);
	Appointment_vector.push_back(Appointment_example_9);
	Appointment_vector.push_back(Appointment_example_10);
	Appointment_vector.push_back(Appointment_example_11);
	Appointment_vector.push_back(Appointment_example_12);
	Appointment_vector.push_back(Appointment_example_13);
	Appointment_vector.push_back(Appointment_example_14);
	Appointment_vector.push_back(Appointment_example_15);
	Appointment_vector.push_back(Appointment_example_16);

	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment1, Patient1));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment2, Patient2));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment3, Patient3));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment4, Patient1));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_1, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_2, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_3, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_4, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_5, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_6, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_7, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_8, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_9, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_10, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_11, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_12, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_13, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_14, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_15, Patient5));
	Patient_Appointment.insert(pair<Appointment, Patient>(Appointment_example_16, Patient5));


	int wyjscie_z_petli = 1;

	while(1)
	{
		Main_panel();
		cin >> wyjscie_z_petli;
		if (wyjscie_z_petli < 1 || wyjscie_z_petli > 6)
		{
			break;
		}
		else
		{
			switch (wyjscie_z_petli)
			{
			case 1:
				case_1(Patient_vector, Patient_Appointment, Appointment_vector);
				break;
			case 2:
				case_2(Doctor_vector);
				break;
			case 3:
				case_3(Patient_Appointment);
				break;
			case 4:
			{
				Patient Tmp_Patient = case_5();
				Appointment Tmp_Appointment = case_4(Patient_Appointment);
				if (Tmp_Appointment.get_PWZ_number() == "0")
				{
					cout << "Jeden lekarz nie moze przyjac wiecej niz 16 pacjentow jednego dnia" << endl;
				}
				else
				{
					Patient_Appointment.insert(pair<Appointment, Patient>(Tmp_Appointment, Tmp_Patient));
				}
				break;
			}
			case 5:
				Patient_vector.push_back(case_5());
				break;
			case 6:
				Doctor_vector.push_back(case_6());
				break;
			default:
				wyjscie_z_petli = 99;
				break;
			}
		}
	}
}