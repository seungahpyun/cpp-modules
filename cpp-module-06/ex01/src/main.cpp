/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/04 09:51:38 by spyun         #+#    #+#                 */
/*   Updated: 2025/08/04 10:27:54 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data *data = new Data();
	data->i = 42;
	std::cout << "Original Data: " << data->i << std::endl;

	uintptr_t serializedData = Serializer::serialize(data);
	std::cout << "Serialized Data: " << serializedData << std::endl;

	Data *deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized Data: " << deserializedData->i << std::endl;

	// note: if free here then segmentation fault occurs
	// because deserializedData points to the same memory as data, which is deleted
	// delete data;
	// delete deserializedData;
	return 0;
}
