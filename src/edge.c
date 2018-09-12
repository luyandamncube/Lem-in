/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:17:26 by lmncube           #+#    #+#             */
/*   Updated: 2018/09/12 15:27:13 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	edge(int *V, int k, t_node *list)
{
	V[k] = malloc(sizeof(t_node));

}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
