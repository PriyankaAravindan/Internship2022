import pulp
import scipy.optimize
from ortools.linear_solver import pywraplp

def create_data_model():
    """Stores the data for the problem."""
    data = {}
    data['constraint_coeffs'] = [[40, 50, 30, 10, 10, 40, 30]]
    data['bounds'] = [100]
    data['obj_coeffs'] = [40, 60, 10, 10, 3, 20, 60]
    data['num_vars'] = 7
    data['num_constraints'] = 1
    return data



def main():
    data = create_data_model()

    solver = solver = pywraplp.Solver.CreateSolver('SCIP')
    x = {}
    for j in range(data['num_vars']):
        x[j] = solver.BoolVar('x[%i]' % j)
    print('Number of variables =', solver.NumVariables())

    for i in range(data['num_constraints']):
        constraint = solver.RowConstraint(0, data['bounds'][i], '')
        for j in range(data['num_vars']):
            constraint.SetCoefficient(x[j], data['constraint_coeffs'][i][j])
    print('Number of solverconstraints =', solver.NumConstraints())



    objective_terms = [ data['obj_coeffs'][i] * x[j] for i in range(data['num_vars'])] 
    print(objective_terms)
    solver.Maximize(solver.Sum(objective_terms))

    status = solver.Solve()

    if status == pywraplp.Solver.OPTIMAL:

        print('Objective value =', solver.Objective().Value())
        for j in range(data['num_vars']):
            print(x[j].name(), ' = ', x[j].solution_value())
        print('Problem solved in %f milliseconds' % solver.wall_time())
        print('Problem solved in %d iterations' % solver.iterations())
        print('Problem solved in %d branch-and-bound nodes' % solver.nodes())

    else:
        print('The problem does not have an optimal solution.')


if __name__ == '__main__':
    main()


