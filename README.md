# GSA
# Part 1. Conduct Global Sensitivity Analysis Using Matlab

To perform global sensitivity analysis One needs to save the model function of a trained model which is trained using "Regression Learner". The function name is trainRegressionModel. The C-code modifies the function "trainRegressionModel" by omitting a specific descriptor. Then one do "nrun" training to investigate the indispensability casued by the variable group.

gsa.m: sample matlab code
modify_fun_matlab.exe: function to remove feature groups, to be called by gsa.m
modify_fun_matlab.c: C-code.

==============================================================================
# Part 2. Predict if a set of compounds are aggregators or not using two established machine learning models

Step 1A is to generate FP2 fingerprint using openbabel, and then run hex2bin to get binary file.

babel -imol2 sample.mol2 -ofps sample_FP2.fs -xfFP2
hex2bin.exe -i sample_FP2.fs -o sample_FP2.txt

Step 1B is to generate rdkit descriptor using python code. More details please refer to
https://www.rdkit.org/docs/index.html.
The rdkit properties are listed in 'rdkit_prop.list'.

Step 2.
make prediction using predict_fp2.exe or predict_rdkit.exe

predict_rdkit.exe -i test_rdkit.txt -o predict_rdkit.out
predict_fp2.exe -i test_fp2.txt -o predict_fp2.out

