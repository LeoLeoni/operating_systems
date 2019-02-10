using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ErrorCheckStudentInfo
{
    class StudentChecker
    {
        private double _minScore;
        private double _maxScore; //build accessors next class
        private double _minSemesterStanding;
        private double _maxSemesterStanding;
        public StudentChecker()
        {
            _minScore = 0.0;
            _maxScore = 100.0;
            _minSemesterStanding = 1;
            _maxSemesterStanding = 14;
        }
        //alternative to take in args for student checker
        public StudentChecker(double minScore, double maxScore)
        {
            _minScore = minScore;
            _maxScore = maxScore;
            _minSemesterStanding = 1;
            _maxSemesterStanding = 14;
        }
        public StudentChecker(double minScore, double maxScore, int minSemester, int maxSemester)
        {
            _minScore = minScore;
            _maxScore = maxScore;
            _minSemesterStanding = minSemester;
            _maxSemesterStanding = maxSemester;
        }

        /// <summary>
        /// Validates a students semester standing
        /// </summary>
        /// <param name="semester">Semester standing to be checked</param>
        /// <returns>Returns if the semester is valid</returns>
        public bool CheckSemesterStanding (int semester)
        {
            return !(semester < _minSemesterStanding || semester > _maxSemesterStanding);
        }

        /// <summary>
        /// Validates a score against the minimum and maximum possible
        /// </summary>
        /// <param name="testScore">Score to be checked</param>
        /// <returns>Return if the score is valid</returns>
        public bool CheckScore(double testScore)
        {
            return testScore < _minScore || testScore > _maxScore ? false : true;
        }
    }
}
