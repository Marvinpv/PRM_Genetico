import pandas as pd
import numpy as np
import sys
import os
import matplotlib.pyplot as plt

#Execute script from parent directory: python3 src/create_tables.py

path_results = './results/'
path_tables = './tables/'
n_rooms = 4

result_files = os.listdir(path_results)

#print(result_files)

filenames = [filename.split('.')[0] for filename in result_files]


def crear_tablas_html(path_salida,path_entrada,num_rooms):
    result_files = os.listdir(path_entrada)
    pagina_var = """<!DOCTYPE html><html>
        <head><title>Executions over set of rooms</title>
        <link rel="stylesheet" href="estilo.css">
        <meta charset="utf8"></head>
        <body><h1>EXECUTION OVER SET OF ROOMS</h1>"""

    for room in range(num_rooms):
        files_room = [fname for fname in result_files if '_'+str(room+1)+'_' in fname ] 
        visibility_values = np.array([])
        points = np.array([])
        pagina_var += """
        <p><table>
        <tr>
            <th colspan="5"> ROOM NR """+str(room+1)+""" </th>
        </tr>
        <tr>
            <th>Algorithm</th>
            <th>Points</th>
            <th>Fitness</th>
            <th>Visibility(%)</th>
            <th>Time(s)</th>
        </tr>
        """
        names = []
        for froom in files_room:
            globalFrame = pd.DataFrame({'Points':[], 'Fitness':[], 'Visibility':[], 'Time':[]})
            df = pd.read_csv(path_entrada+froom)
            globalFrame = pd.concat([globalFrame, df],ignore_index=True)
            #print(globalFrame)
            if visibility_values.size == 0:
                visibility_values = np.array(globalFrame['Visibility'])
            else:
                visibility_values = np.vstack((visibility_values,np.array(globalFrame['Visibility'])))



            if 'agg' in froom:
                algoritmo = 'AGG'
            elif 'age' in froom:
                algoritmo = 'AGE'
            elif 'shade' in froom:
                algoritmo = 'SHADE'
            elif 'vis' in froom:
                algoritmo = 'VISIBILITY GRAPH'
                points = np.array(globalFrame['Points'])

            names.append(algoritmo)
            
            mean_points = globalFrame['Points'].mean()
            #print('Mean Points:',mean_points)
            mean_fitness = globalFrame['Fitness'].mean()
            mean_visibility = globalFrame['Visibility'].mean()
            mean_time = globalFrame['Time'].mean()
            pagina_var += f"""
                <tr>
                    <td style="text_align:center">{algoritmo}</td>
                    <td style="text_align:center">{mean_points:.02f}</td>
                    <td style="text_align:center">{mean_fitness:.02f}</td>
                    <td style="text_align:center">{mean_visibility*100:.02f}</td>
                    <td style="text_align:center">{mean_time/(10**9):.06f}</td>
                </tr>
                """
        
        pagina_var += """
            </table></p>
            """


        plt.boxplot(visibility_values.T)
        plt.title('Room nr ' + str(room + 1))
        plt.xticks(range(1,len(names)+1),names)
        
        #plt.show()
        plt.savefig(path_tables+'vis_room'+str(room+1)+'.jpg')
        plt.clf()
        plt.boxplot(points)
        plt.title('Visibility Graph - Room nr '+str(room+1)+' - points used')
        plt.savefig(path_tables+'vis_graph_points_room'+str(room+1)+'.jpg')
        plt.clf()
    
    pagina_var += '</body></html>'

    with open(path_salida + 'results_tables.html','w') as salida:
        salida.write(pagina_var)



if __name__ == "__main__":
    crear_tablas_html('./tables/','./results/',n_rooms)