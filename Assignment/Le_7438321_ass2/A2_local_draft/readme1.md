Lab 1: The Human Resources division tracks information about the employees and the facilities:
In the Human Resource (HR) records, each employee has an identification number, e-mail address, job identification code, salary, and manager. Some employees earn commissions in addition to their salary.

The company also tracks information about jobs within the organization. Each job has an identification code, job title, and a minimum and maximum salary range for the job.
Some employees have been with the company for a long time and have held different positions within the company. When an employee resigns, the duration the employee was working, the job identification number, and the department are recorded. - Job_History

The sample company is regionally diverse, so it tracks the locations of its warehouses and departments. Each employee is assigned to a department, and each department is identified either by a unique department number or a short name.

Each department is associated with one location, and each location has a full address that includes the street name, postal code, city, state or province, and the country code. In places where the departments and warehouses are located, the company records details such as the > Country (country name, currency symbol, currency name, and the region where the country is located geographically.

Entity:
- Employee(identification number:PK, e-mail address, job indent code, salary, manager), bonus: optional
- 