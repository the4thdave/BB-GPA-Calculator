#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GPA {
public:
	
	void init(double &cum_grade_points, double &cum_gpa, int &cum_credits) {
		cum_gpa = 0;
		cum_grade_points = 0;
		cum_credits = 0;
	}

	void initialize(double &grade_points, int &sem_credits) {
		grade_points = 0;
		sem_credits = 0;

		return;
	}

	void get_data(double &grade_points, double &cum_grade_points,
		int &sem_credits, int &cum_credits)
	{
		int classes, credits;
		char g1, g2;
		double class_points;

		cout << "How many classes are you taking this semester? ";
		cin >> classes;

		for (int i = 1; i < classes + 1; ++i) {
			cout << "Class " << i << ": \n";
			cout << "Enter grade (A0, A-, B+): ";
			cin >> g1 >> g2;
			class_points = calc_class_points(g1, g2);
			cout << "Enter credits: ";
			cin >> credits;

			grade_points += (class_points * credits);
			sem_credits += credits;
			cum_grade_points += (class_points * credits);
			cum_credits += credits;
		}
		return;
	}

	void calc_gpa(double &grade_points, double &cum_grade_points,
		double &cum_gpa, int &sem_credits, int &cum_credits, 
		vector<double> &gpa_vec)
	{
		cum_gpa = cum_grade_points / cum_credits;

		string str_cum_gpa = to_string(cum_gpa); 

		if (str_cum_gpa.size() > 4) {
			cum_gpa = double(int(cum_gpa * 100 + 0.5)) / 100;
		}

		double sem_gpa = grade_points / sem_credits;

		string str_gpa = to_string(sem_gpa);

		if (str_gpa.size() > 4) {
			sem_gpa = double(int(sem_gpa * 100 + 0.5)) / 100;
			gpa_vec.push_back(sem_gpa);
		}
		else
			gpa_vec.push_back(sem_gpa);

		return;
	}

	bool exit_option() {
		char choice;
		bool is_answering;
		bool is_choosing = true;

		while (is_choosing) {
			cout << "Do you want to add another semester? (Y/N) ";
			cin >> choice;

			if (choice == 'Y' || choice == 'y') {
				is_choosing = false;
				is_answering = true;
			}
			else if (choice == 'N' || choice == 'n') {
				is_choosing = false;
				is_answering = false;
			}
			else
				cout << "Invalid choice. Please answer with Y or N.\n";
		}
		return is_answering;
	}

	double calc_class_points(char c1, char c2) {
		double gpa_array[] = { 4.0, 3.7, 3.3, 3.0, 2.7, 2.3,
			2.0, 1.7, 1.3, 1.0, 0.7 };
		double class_points;

		switch (c1) {
		case 'A':
			if (c2 == '+')
				class_points = gpa_array[0];
			else if (c2 == '0')
				class_points = gpa_array[0];
			else if (c2 == '-')
				class_points = gpa_array[1];
			break;

		case 'B':
			if (c2 == '+')
				class_points = gpa_array[2];
			else if (c2 == '0')
				class_points = gpa_array[3];
			else if (c2 == '-')
				class_points = gpa_array[4];
			break;

		case 'C':
			if (c2 == '+')
				class_points = gpa_array[5];
			else if (c2 == '0')
				class_points = gpa_array[6];
			else if (c2 == '-')
				class_points = gpa_array[7];
			break;

		case 'D':
			if (c2 == '+')
				class_points = gpa_array[8];
			else if (c2 == '0')
				class_points = gpa_array[9];
			else if (c2 == '-')
				class_points = gpa_array[10];
			break;

		case 'F':
			class_points = 0.0;
			break;

		default:
			cout << "Invalid input. Please enter grade (A-, B0, C+)\n";
		}
		return class_points;
	}
};

int main() {
	GPA obj1;
	double grades, cumul_points, sem_gpa, cum_gpa;
	int credits, cum_credits;
	vector<double> dub_gpa_vec;
	bool is_answering = true;

	obj1.init(cumul_points, cum_gpa, cum_credits);

	while (is_answering) {
		obj1.initialize(grades, credits);

		obj1.get_data(grades, cumul_points, credits, cum_credits);

		obj1.calc_gpa(grades, cumul_points, cum_gpa, credits, cum_credits,
			dub_gpa_vec);

		is_answering = obj1.exit_option();
	}

	cout << grades << "\n" << credits << "\n" << cumul_points << " " <<
		cum_credits << "\n" << cum_gpa << endl;

	return 0;
}