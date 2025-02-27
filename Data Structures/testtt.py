import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

df = pd.read_csv('Churn_Modelling.csv')  # Uncomment and specify your dataset

# Numerical columns for box plots
numcols = ['CreditScore', 'Age', 'Tenure', 'Balance', 'EstimatedSalary']

# Create subplots (3 rows, 2 columns)
fig, ax = plt.subplots(3, 2, figsize=(15, 15))

# Plot boxplots for each numerical column
for i, subplot in zip(numcols, ax.flatten()):
    sns.boxplot(x='Exited', y=i, data=df, ax=subplot)

# Adjust layout for better visibility
plt.tight_layout()
plt.show()
